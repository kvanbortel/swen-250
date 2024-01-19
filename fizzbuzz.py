def main() -> None:
    for i in range(1, 101):
        if i % 5 == 0 and i % 7 == 0:
            print("FizzBuzz")
        elif i % 5 == 0:
            print("Fizz")
        elif i % 7 == 0:
            print("Buzz")
        else:
            print(i)


if __name__ == "__main__":
    main()

