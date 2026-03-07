#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define NxN (N*N)
#define TRUE 1
#define FALSE 0

struct node {
	int tiles[N][N]; // 4x4
	int f, g, h;
    // heuristic function parts
    // f - total cost
    // g - current path cost (start -> current)
    // h - estimated shortest path cost (current -> goal)
	short zero_row, zero_column;	/* location (row and column) of the empty tile */
	struct node *next;              /* linked list part */
	struct node *parent;			/* used to trace back the solution */
};

int goal_rows[NxN];
int goal_columns[NxN];
struct node *start,*goal;
struct node *open = NULL, *closed = NULL; // open - fringe
struct node *succ_nodes[4]; // 4 adjacent nodes (at most, so this should not include the current node)
// if there are less than 2 successors, some successors must be made NULL
// bc null pointers...

void print_a_node(struct node *pnode) {
	int i,j;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) 
			printf("%2d ", pnode->tiles[i][j]);
		printf("\n");

	}

	printf("\n");
}

struct node *initialize(char **argv){
	int i,j,k,index, tile;
	struct node *pnode;
	pnode=(struct node *) malloc(sizeof(struct node));
	index = 1;
	for (j=0;j<N;j++){
		for (k=0;k<N;k++) {
			tile=atoi(argv[index++]);
			pnode->tiles[j][k]=tile;
			if(tile==0) {
				pnode->zero_row=j;
				pnode->zero_column=k;
			}
		}
	}
	pnode->f=0;
	pnode->g=0;
	pnode->h=0;
	pnode->next=NULL;
	pnode->parent=NULL;
	start=pnode;
	printf("initial state\n");
	print_a_node(start);
	pnode=(struct node *) malloc(sizeof(struct node));
	goal_rows[0]=3;
	goal_columns[0]=3;
	for(index=1; index<NxN; index++){
		j=(index-1)/N;
		k=(index-1)%N;
		goal_rows[index]=j;
		goal_columns[index]=k;
		pnode->tiles[j][k]=index;
	}
	pnode->tiles[N-1][N-1]=0;       /* empty tile=0 */
	pnode->f=0;
	pnode->g=0;
	pnode->h=0;
	pnode->next=NULL;
	goal=pnode; 
	printf("goal state\n");
	print_a_node(goal);
	return start;
}
/* merge the remaining nodes pointed by succ_nodes[] into open list. 
 * Insert nodes based on their f values --- keep f values sorted. */
void merge_to_open() { 
	for (int i = 0; i<4; i++){
		if (succ_nodes[i] != NULL){
			struct node *pnode = succ_nodes[i];
			struct node *pnode2 = NULL;
			struct node *head = open;
			
			if ( open == NULL || pnode->f <= open->f){
				pnode->next = open;
				open = pnode;
			}
			else{
				while(open->next!=NULL){
					if (open->f < pnode->f && open->next->f >= pnode->f){
						pnode2 = open->next;
						open->next = pnode;
						pnode->next = pnode2;
						break;
					}
					open = open->next;
				}

				if (open->next == NULL && open->f < pnode->f){
					open->next = pnode;
					pnode->next = NULL;
					open = head;
				}
			}
		}
	}

}

/*swap two tiles in a node*/
void swap(int row1,int column1,int row2,int column2, struct node * pnode){
	int tile = pnode->tiles[row1][column1];
	pnode->tiles[row1][column1]=pnode->tiles[row2][column2];
	pnode->tiles[row2][column2]=tile;
}


/*update the f,g,h function values for a node */
void update_fgh(int i) {
	
	if (succ_nodes[i]!=NULL){
		struct node *pnode = succ_nodes[i];
		int tot = 0;
		pnode->h = 0;
		if (pnode->parent == NULL){
			pnode->g = 1;
		} 
		else{
			pnode->g = (pnode->parent->g)+1;
		}
		for (int x=0; x<16;x++){ //iterate from 1 to 15 to see where the numbers are to calculate manhattan distance
			int goal_y = 0;
			int goal_z = 0;
			int curr_y = 0;
			int curr_z = 0;
			for (int y=0; y<4;y++){
				for (int z=0; z<4;z++){
					if (pnode->tiles[y][z] == x){
						curr_y=y;
						curr_z = z;
					}
					if (goal->tiles[y][z] == x){
						goal_y = y;
						goal_z = z;
					}

				}
			}
			tot = tot + (abs(goal_y - curr_y) + abs(goal_z - curr_z));
		}
		pnode->h = tot;
		pnode->f = pnode->h + pnode->g;
		// printf("f value: %d for the struct: \n",pnode->f);
		// print_a_node(pnode);
		// printf("end in the funct. ");

	}
}

/* 0 goes down by a row */
void move_down(struct node * pnode){
	swap(pnode->zero_row, pnode->zero_column, pnode->zero_row+1, pnode->zero_column, pnode); 
	pnode->zero_row++;
}

/* 0 goes right by a column */
void move_right(struct node * pnode){
	swap(pnode->zero_row, pnode->zero_column, pnode->zero_row, pnode->zero_column+1, pnode); 
	pnode->zero_column++;
}

/* 0 goes up by a row */
void move_up(struct node * pnode){
	swap(pnode->zero_row, pnode->zero_column, pnode->zero_row-1, pnode->zero_column, pnode); 
	pnode->zero_row--;
}

/* 0 goes left by a column */
void move_left(struct node * pnode){
	swap(pnode->zero_row, pnode->zero_column, pnode->zero_row, pnode->zero_column-1, pnode); 
	pnode->zero_column--;
}

/* expand a node, get its children nodes, and organize the children nodes using
 * array succ_nodes.
 */
void expand(struct node *selected) {
	struct node *pnode = selected;
	struct node *right = (struct node *) malloc(sizeof(struct node));
	struct node *left = (struct node *) malloc(sizeof(struct node));
	struct node *up = (struct node *) malloc(sizeof(struct node));
	struct node *down = (struct node *) malloc(sizeof(struct node));
	if (pnode->zero_column != 3){
		move_right(pnode);
		for (int j=0;j<N;j++){
			for (int k=0;k<N;k++) {
				right->tiles[j][k] = pnode->tiles[j][k];
				if(pnode->tiles[j][k]==0) {
					right->zero_row=j;
					right->zero_column=k;
				}
			}
		}
		right->parent = pnode;
		succ_nodes[0] = right;
		move_left(pnode);

	}
	else{
		succ_nodes[0] = NULL;
		free(right);
	}

	if (pnode->zero_column != 0){
		move_left(pnode);
		for (int j=0;j<N;j++){
			for (int k=0;k<N;k++) {
				left->tiles[j][k] = pnode->tiles[j][k];
				if(pnode->tiles[j][k]==0) {
					left->zero_row=j;
					left->zero_column=k;
				}
			}
		}
		left->parent = pnode;
		succ_nodes[1] = left;
		move_right(pnode);
	}

	else{
		succ_nodes[1] = NULL;
		free(left);
	}
	if (pnode->zero_row != 3){
		move_down(pnode);
		for (int j=0;j<N;j++){
			for (int k=0;k<N;k++) {
				down->tiles[j][k] = pnode->tiles[j][k];
				if(pnode->tiles[j][k]==0) {
					down->zero_row=j;
					down->zero_column=k;
				}
			}
		}
		down->parent = pnode;
		succ_nodes[2] =down;
		move_up(pnode);


	}
	else{
		succ_nodes[2] =NULL;
		free(down);
	}

	if (pnode->zero_row != 0){
		move_up(pnode);
		for (int j=0;j<N;j++){
			for (int k=0;k<N;k++) {
				up->tiles[j][k] = pnode->tiles[j][k];
				if(pnode->tiles[j][k]==0) {
					up->zero_row=j;
					up->zero_column=k;
				}
			}
		}
		down->parent = pnode;
		succ_nodes[3] =up;
		move_down(pnode);
	}
	else{
		succ_nodes[3] =NULL;
		free(up);
	}
}

int nodes_same(struct node *a,struct node *b) {
	int flg=FALSE;
	if (memcmp(a->tiles, b->tiles, sizeof(int)*NxN) == 0)
		flg=TRUE;
	return flg;
}

/* Filtering. Some states in the nodes pointed by succ_nodes may already be
included in
 * either open or closed list. There is no need to check these states. Release the
 * corresponding nodes and set the corresponding pointers in succ_nodes to NULL.
This is
 * important to reduce execution time.
 * This function checks the (i)th node pointed by succ_nodes array. You must call
this
 * function in a loop to check all the nodes in succ_nodes. Free the successor node
and
 * set the corresponding pointer to NULL in succ_node[] if a matching node is found
in
 * the list.
 */

void filter(int i, struct node *pnode_list){ 
	struct node *pnode = succ_nodes[i];
	struct node *pnode2 = pnode_list;
	while(pnode_list!=NULL){
		if (nodes_same(pnode,pnode_list)){
			succ_nodes[i] = NULL;
		}
		pnode_list = pnode_list->next;
	}
	pnode_list = pnode2;
}

int main(int argc,char **argv) {
	int iter,cnt;
	struct node *copen, *cp, *solution_path;
    // copen - node to expand
	int ret, i, pathlen=0, index[N-1]; 
	printf("arrives?-1");
	solution_path=NULL;
	
	start=initialize(argv);	/* init initial and goal states */
	open=start; 
	iter=0;
	while (open!=NULL) {	/* Termination cond with a solution is tested in expand. */
         // above: step 4 from pseudo-code slides
		copen=open;
		open=open->next;
		  /* get the first node from open to expand */
		
    //     // above removes first node
		if(nodes_same(copen,goal)){ /* goal is found */
			do{ /* trace back and add the nodes on the path to a list */
				copen->next=solution_path;
				solution_path=copen;
				copen=copen->parent;
				pathlen++;
			} while(copen!=NULL);
			printf("Path (lengh=%d):\n", pathlen); 
			copen=solution_path;
  			while(copen!=NULL) {
    			print_a_node(copen);
    			copen=copen->next;
  			}
			break;
		}
		printf("arrives?");
		expand(copen);       /* Find new successors */
		// printf("enters?3");
		for(i=0;i<4;i++){
			
			if (succ_nodes[i]!=NULL){
				printf("enter if \n");
				filter(i,open);
				filter(i,closed);
				update_fgh(i); // estimate new f, g, h values for the node
			//	print_a_node(succ_nodes[i]);
				printf("end if \n");
			}
			
		}
		printf("out of for \n");

		merge_to_open(); /* New open list */
		copen->next=closed;
		closed=copen;		/* New closed */
		/* print out something so that you know your 
		 * program is still making progress 
		 */
		if (open!=NULL){
			printf("nodes in open \n");
			struct node *temporar = open;

			while (open!= NULL){
				
				print_a_node(open);
				printf("%d \n", open->f);
				open = open->next;
			}
			open = temporar;
		}
		iter++;
		if(iter %1000 == 0)
			printf("iter %d\n", iter);
		
	}
	return 0;
} /* end of main */
