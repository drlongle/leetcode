
import argparse
import datetime
import subprocess

def run_tests(digit):
    sum = 0
    low, high = 1, 1000000000
    for x in range(low, high+1):
        x_str = str(x)
        sum += x_str.count(digit)
        cmd = ["./solution", digit, "1", str(x)]
        output = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True).stdout
        output = int(output)
        if x % 10000 == 0:
            now = datetime.datetime.now()
            print(f"{now} {x} tests executed")
        if sum != output:
            raise RuntimeError(f"x: {x}, output: {output}, expected: {sum}")
    now = datetime.datetime.now()
    print(f"{now} All {high} tests executed")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("digit")
    args = parser.parse_args()
    run_tests(args.digit)
