# Freivalds-Algorithm-c
C implementation of Freivalds' algorithm for matrix multiplication verification

Matrix multiplication is expensive O(n^3) operations! But what if we could verify the result without doing the full computation?

I implemented Freivalds' algorithm in C to probabilistically verify whether AB = C for three n*n matrices. It’s fast, elegant, and surprisingly effective.

🔍 How it works:
- Pick a random vector x which elements belongs to {0,1}
- Check if A(Bx) = Cx
- If not, then AB!=C
- If yes, repeat a few times to reduce error probability

💡 The math guarantees that if AB!=C, the test fails with probability <= 50% each time. So with just a few repetitions, we get high confidence.
