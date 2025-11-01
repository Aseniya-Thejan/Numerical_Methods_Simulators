# Newton–Raphson Method — Root Finder (C)

A C program that implements the **Newton–Raphson** iterative algorithm to find roots of a nonlinear equation.  
The function defined in this version is:

\[
f(x) = x^2 - 9x + 10
\]
with derivative  
\[
f'(x) = 2x - 9
\]

The program takes an initial guess and required significant digits, then iteratively refines the estimate using Newton–Raphson updates until the relative approximate error meets the specified threshold.

---

## ⚙️ Features

- Uses symbolic derivative \( f'(x) \) directly for faster convergence  
- Dynamically computes relative approximate error at each iteration  
- Displays a formatted iteration table  
- Terminates when error ≤ \( 0.5 × 10^{(2−s)} \) where *s* is significant digits  
- Handles case where the initial guess is already a root  

---

## 🧮 Algorithm

**Newton–Raphson Formula:**

\[
x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
\]

**Error Estimate:**

\[
E_a(\%) = \left|\frac{x_{n+1} - x_n}{x_{n+1}}\right| \times 100
\]

The iteration continues until \( E_a < 0.5 × 10^{(2−s)} \).

---

## 🧑‍💻 Build

```bash
# GCC build (with math library)
gcc -O2 -Wall -Wextra -o newton_raphson Newtonraphson.c -lm
```

---

## ▶️ Run

```bash
./newton_raphson
```

Example interactive session:

```
Enter the initial guess :- 5
Enter the required no of significant digits required :- 4
	   |   X   |   Approximation   |   Error   |
	   -----------------------------------------
	    5.000000   3.750000 	33.333333
	    3.750000   3.400000 	10.294118
	    3.400000   3.330000 	2.100840
Root is 3.33
```

---

## 🧾 Input / Output

- **Input:**  
  - `Initial guess` (double)  
  - `Significant digits` (integer ≥ 1)

- **Output:**  
  - Iteration table showing each approximation and percentage error  
  - Final root estimate once error tolerance is met  

---

## 📂 File Description

- `Newtonraphson.c` — Implements:
  - Function definitions: `f(x)` and `dy_dx(x)`  
  - Iterative Newton–Raphson logic  
  - Error estimation and convergence check  
  - Console printing for progress tracking

---

## 📈 Example Equation Behavior

For `f(x) = x² - 9x + 10`:

- Theoretical roots are `x = 1` and `x = 10`
- Depending on the initial guess, the iteration converges to one of them:
  - `x₀ = 2` → converges to `1`
  - `x₀ = 8` → converges to `10`

---

## ⚠️ Notes

- Avoid initial guesses where \( f'(x) = 0 \), as this causes division by zero.  
- For functions with multiple roots, convergence depends on the chosen initial guess.  
- Convergence is quadratic if the derivative is not zero near the root.  
- The program currently uses **relative approximate error**, not absolute difference.

---

## 🧠 References

- Chapra & Canale, *Numerical Methods for Engineers*, McGraw-Hill.  
- Burden & Faires, *Numerical Analysis*, Cengage Learning.

---

## 🪪 License

MIT License — free to modify and redistribute.
