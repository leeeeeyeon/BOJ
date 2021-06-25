from fractions import Fraction

a, b = map(int, input().split())
c, d = map(int, input().split())

answer = Fraction(a, b) + Fraction(c, d)

print(answer.numerator, answer.denominator)