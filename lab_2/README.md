Main task was to decompose function y = $\sqrt[n]{a}$ into a row with a recursive formula

$$
y_{i+1} = \frac{y_i}{n^2} * \left( (n^2 - 1) + \frac{1}{2} \cdot (n + 1) \cdot \frac{a}{y_i ^ n} - \frac{1}{2} * (n - 1) * \frac{y_i ^ n}{a} \right)
$$

There were to ways to specify the precision

* Specifying number of members
* Specifying precision

Additional tasks:
1. Count upper and lower restrictions for input values
2. Zero row member (zero index) restrictions
3. Get a diff of values computed with pow from <math.h>
4. Print number of iterations it took during computation
