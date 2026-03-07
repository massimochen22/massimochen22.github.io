# massimochen22.github.io

Personal portfolio website for **Hao Massimo Chen** — Application Developer at ADP.

🔗 **Live site:** [massimochen22.github.io](https://massimochen22.github.io)

---

## About

A single-page portfolio built from scratch with a dark-theme, minimalist design. It covers my work experience, skills, school projects, and contact information.

---

## Tech Stack

| Layer | Tech |
|---|---|
| Markup | HTML5 |
| Styling | CSS3 (custom properties, grid, flexbox) |
| Framework | Bootstrap 4 |
| Icons | Font Awesome |
| Fonts | Inter (Google Fonts) |
| Interactions | Vanilla JS + jQuery |
| Text animation | simple-text-rotator |
| Form handling | Formspree (with `mailto:` fallback) |
| Hosting | GitHub Pages |

---

## Sections

- **Hero** — Name, animated role rotator, background photo
- **About** — Bio, current role at ADP, skills
- **Projects** — School & personal projects (E-Commerce Store, HTML5 Game, Pong, Fortran Compiler)
- **School** — NJIT graduation details
- **Contact** — Contact form, social links

---

## Projects Showcased

| Project | Description | Stack |
|---|---|---|
| [E-Commerce Store](https://hc424-prod.herokuapp.com/Project/login.php) | Full-stack shopping platform | PHP, MySQL, Bootstrap |
| [HTML5 Game](example/html5.html) | Browser-based Canvas game | HTML5, JavaScript |
| [Pong Game](HW5/pong.html) | Classic Pong recreation | JavaScript, Canvas |
| [Fortran Compiler](https://github.com/massimochen22/FortranBasedLanguage-Compiler) | Lexer/parser/interpreter in C++ | C++ |

---

## Running Locally

No build step required — just open `index.html` in a browser, or serve it with any static server:

```bash
# Python
python3 -m http.server 8000

# Node (npx)
npx serve .
```

Then visit `http://localhost:8000`.

---

## Contact Form Setup

The contact form uses [Formspree](https://formspree.io) for email delivery. To activate:

1. Sign up at formspree.io (free)
2. Create a new form → set email to `haomassimochen@gmail.com`
3. In `index.html`, replace `YOUR_FORM_ID` with your form's ID:
   ```html
   action="https://formspree.io/f/YOUR_FORM_ID"
   ```

Until configured, the form falls back to opening your default mail client.

---

## Contact

- 📧 haomassimochen@gmail.com
- 💼 [LinkedIn](http://linkedin.com/in/massimo-chen-6b9930206)
- 🐙 [GitHub](http://github.com/massimochen22)
