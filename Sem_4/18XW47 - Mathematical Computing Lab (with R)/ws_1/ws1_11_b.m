syms a b

expr = [(2*pi*sqrt(0.5*(a^2+b^2))) == 20, (2*a == b), a > 0, b > 0];
vars = [a b]
[sola solb] = solve(expr, vars)