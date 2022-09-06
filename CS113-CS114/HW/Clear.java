import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.util.Arrays;

public class Clear {

	public static void main(String[] args) throws IOException {
		int pics = 17;
		File[] file = new File[pics];
		// String prefix = "../resource/asnlib/publicdata/";
		String prefix = "";
		for (int p = 1; p <= pics; ++p) {
			String suff = String.valueOf(p);
			String filename = prefix + "birds" + suff + ".ppm";

			System.out.println("Opening " + filename);
			file[p - 1] = new File(filename);
		}

		long start = System.currentTimeMillis();

		// create a scanner for each of the pictures
		//
		Scanner[] scan = new Scanner[pics];

		int rows = 0, cols = 0, mx = 0;
		for (int i = 0; i < pics; ++i) {
			try {
				scan[i] = new Scanner(file[i]);
				String line = scan[i].nextLine();
				cols = Integer.parseInt(scan[i].next());
				rows = Integer.parseInt(scan[i].next());
				mx = Integer.parseInt(scan[i].next());
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		
		Scanner[] scan2 = new Scanner[pics];

		for (int ix = 0; ix < pics; ++ix) {
			try {
				scan2[ix] = new Scanner(file[ix]);
				scan2[ix].nextLine();
				scan2[ix].nextLine();
				scan2[ix].nextLine();
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		// open output file and print out header

		BufferedWriter output = new BufferedWriter(new FileWriter("cleared.ppm"));
		output.write(String.format("%s\n", "P3"));
		output.write(String.format("%d  %d\n", cols, rows));
		output.write(String.format("%d\n", mx));
		System.out.println(rows + ", " + cols + ", " + mx);

		for (int i = 0; i < cols; ++i) {
			for (int j = 0; j < rows; ++j) {
				// read in red, green, blue
				for (int c = 0; c < 3; ++c) {
					int avg = 0;
					int avg2 = 0;
					int count = 0;
					for (int k = 0; k < pics; ++k) {
						avg += Integer.parseInt(scan[k].next());
					}
					avg = avg / pics;
					for (int l = 0; l < pics; ++l) {
						int randNum = Integer.parseInt(scan2[l].next());
						if (randNum > avg ||randNum == avg) {
							avg2 += randNum;
							count++;
						}
					}
					avg2 = avg2 / count;
					output.write(String.format("%d ", avg2));
				}
			}
			output.write(String.format("\n"));
		}

		for (int i = 0; i < pics; ++i) {
			scan[i].close();
		}
		output.close();
	}
}
