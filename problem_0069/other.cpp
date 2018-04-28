/*
x_(n+1) = x_n - f(x_n) / f'(x_n)

x = sqrt(S) where S is the parameter x
x^2 = S

f(x_n) = x_n^2 - S = 0
f'(x_n) = 2 * x_n

From the first sentence,
x_(n+1) = x_n - (x_n^2 - S) / 2 * x_n
x_(n+1) = (x_n + S / x_n) / 2

From the code,
ans = (ans + x / ans) / 2;

I.E. get x where f(x) = x^7 + x^4 + x^2 + 1 = 0

f(x) = x^7 + x^4 + x^2 + 1
f'(x) = 7x^6 + 4x^3 + 2*x

while( > delta)
{
x_(n+1) = x_n - (x_n^7 + x_n^4 + x_n^2 + 1) / (7x_n^6 + 4x_n^3 + 2*x_n)
}

return x(n_1)
// depending initial value and the status of the graph, the result may vary.

x_(n+1) = x_n - f(x_n) / f'(x_n)

x = sqrt(S) where S is the parameter x
x^2 = S

f(x_n) = x_n^2 - S = 0
f'(x_n) = 2 * x_n

From the first sentence,
x_(n+1) = x_n - (x_n^2 - S) / 2 * x_n
x_(n+1) = (x_n + S / x_n) / 2

From the code,
ans = (ans + x / ans) / 2;

I.E. get x where f(x) = x^7 + x^4 + x^2 + 1 = 0

f(x) = x^7 + x^4 + x^2 + 1
f'(x) = 7x^6 + 4x^3 + 2*x

while( > delta)
{
x_(n+1) = x_n - (x_n^7 + x_n^4 + x_n^2 + 1) / (7x_n^6 + 4x_n^3 + 2*x_n)
}

return x(n_1)
depending initial value and the status of the graph, the result may vary.
*/

int sqrt(int x) {
    double ans    = x;
    double delta  = 0.0001;
    while (fabs(pow(ans, 2) - x) > delta) {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}

