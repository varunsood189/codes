import numpy as np

def conjugate_gradient(A, b, n, x0=None, tol=1e-8):
    """
    Solve the system Ax = b using the Conjugate Gradient method.
    
    :param A: Symmetric positive-definite matrix
    :param b: Right-hand side vector
    :param n: Maximum number of iterations
    :param x0: Initial guess for solution (default is zero vector)
    :param tol: Convergence tolerance
    :return: Solution vector x
    """
    # calculate initial residual vector
    x = np.zeros_like(b)
    r = b-A.dot(x)
    p=r
    for i in range(n):
        a =r.dot(r)/(p.T.dot(A).dot(p))
        x =x+ a*p
        r1 = r- a*A.dot(p)
        if np.linalg.norm(r1)<tol:
            break
        b = r1.dot(r1)/r.dot(r)
        p = r1+b*p
        r=r1
    return x
