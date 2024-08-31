
import argparse

def countDigit(low, high, digit):
    sum = 0
    for x in range(low, high+1):
        x_str = str(x)
        sum += x_str.count(digit)
    return sum

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("digit")
    parser.add_argument("low", type=int)
    parser.add_argument("high", type=int)
    args = parser.parse_args()
    res = countDigit(args.low, args.high, args.digit)
    print(f"{res}")
