# Secant Method — Root Finder (C)

This program implements the **Secant Method** in C to find a real root of a nonlinear equation.  
The current function hardcoded is:

\[
f(x) = x^3 - 5x - 5
\]

The method uses **two initial guesses** and refines them iteratively using the secant formula until the relative approximate error drops below a threshold derived from the desired significant digits.

---

## ⚙️ Features

- Interactive input for first and second guesses  
- Computes **relative approximate error** at each iteration  
- Automatically checks if any initial guess is already a root  
- Stops when `error ≤ 0.5 × 10^(2−s)` where *s* = significant digits  
- Prints iteration table including approximations and errors  

---

## 🧮 Algorithm

**Secant formula:**

\[
x_{n+1} = x_n - f(x_n) \times \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}
\]

**Error estimation:**

\[
E_a(\%) = \left|\frac{x_{n+1} - x_n}{x_{n+1}}\right| \times 100
\]

Iteration continues until \(E_a < 0.5 × 10^{(2−s)}\).

---

## 🧑‍💻 Build

```bash
# GCC build command (with math library)
gcc -O2 -Wall -Wextra -o secant Secant.c -lm
```

---

## ▶️ Run

```bash
./secant
```

Example interactive session:

```
Enter the first guess :- 2
Enter the Second guess :- 3
Enter the required no of significant digits required :- 5
	   |   x1     |     x2     |   Approximation   |   Error   |
	   ---------------------------------------------------------
	    2.000000   3.000000 	2.333333 	  N/A
	    3.000000   2.333333 	2.254901 	3.481481%
	    2.333333   2.254901 	2.252939 	0.087002%
Root is 2.252939
```

---

## 🧾 Input / Output

- **Input:**  
  - `x1` → first initial guess  
  - `x2` → second initial guess  
  - `sigd` → number of significant digits  

- **Output:**  
  - Iteration table: `x1`, `x2`, `approximation`, and `% error`  
  - Final root estimate  

---

## 📂 File Description

- `Secant.c` — contains:
  - Function `f(x)` definition  
  - Iterative secant update logic  
  - Error computation  
  - Table output  

---

## 📈 Behavior for f(x) = x³ − 5x − 5

- Equation has a real root near **x ≈ 2.2529**  
- Depending on initial guesses:
  - `(x1, x2) = (2, 3)` → converges to **≈ 2.2529**
  - Convergence may fail if `f(x1)` and `f(x2)` are too close or derivative behavior is flat  

---

## ⚠️ Notes

- Avoid guesses that make `f(x1) ≈ f(x2)` (causes division by near-zero).  
- Convergence is **superlinear**, slower than Newton–Raphson but faster than bisection.  
- Works for continuous functions, but may fail if the root lies between regions with steep slope.  
- Uses **relative approximate error**, not absolute error.  

---

## 🧠 References

- Chapra & Canale, *Numerical Methods for Engineers*  
- Burden & Faires, *Numerical Analysis*

---

## 🪪 License

MIT License — open to modify and redistribute.
