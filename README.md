<h3>This repository involves Problem Set 1 Week 1 from the course CS50’s Introduction to Computer Science</h3>

Each folder contains different solutions to a set of given problems.

<h1>"hello.c" inside folder "world": <strong>Hello, World</strong></h1>

In a file called hello.c, in a folder called world, implement a program in C that prints hello, world\n, and that’s it!

<h1>"hello.c" inside folder "me": <strong>Hello, It's me</strong></h1>

In a file called hello.c, in a folder called me, implement a program in C that prompts the user for their name and then says hello to that user. For instance, if the user’s name is Adele, your program should print hello, Adele\n!

<h1>"mario.c" inside folder "mario-less": <strong>Mario</strong></h1>

Toward the end of World 1-1 in Nintendo’s Super Mario Bros., Mario must ascend right-aligned pyramid of bricks, as in the below.

![image](https://github.com/user-attachments/assets/0945b28a-2323-4ab3-aa36-51ad1ba0b065)

In a file called mario.c in a folder called mario-less, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

![image](https://github.com/user-attachments/assets/77f8bc16-d36f-4804-935e-576c61595b4e)

But prompt the user for an int for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:

![image](https://github.com/user-attachments/assets/0ae14a59-23a9-4406-ae9a-11740785bd34)

Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an int altogether.

<h1>"mario.c" inside folder "mario-more": <strong>Mario</strong></h1>

Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

![image](https://github.com/user-attachments/assets/5fad7adc-2183-4f70-8d9e-96b08e40d7dc)

In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

![image](https://github.com/user-attachments/assets/25845f81-d6dd-4576-88b3-a584b4e2d176)

And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

Examples:
Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

<h1>"cash.c" inside folder "cash": <strong>Cash</strong></h1>

Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy. When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!). In a file called cash.c in a folder called cash, implement a program in C that prints the minimum coins needed to make the given amount of change, in cents, as in the below:

![image](https://github.com/user-attachments/assets/01e42858-432a-4262-9920-041f822ecd3a)

But prompt the user for an int greater than 0, so that the program works for any amount of change:

![image](https://github.com/user-attachments/assets/e62967d1-306d-4007-b3b0-656cb920e6de)

Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).

<h1>"credit.c" inside folder "credit": <strong>Credit</strong></h1>

A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

In a file called credit.c in a folder called credit, implement a program in C that checks the validity of a given credit card number.

<strong>Luhn’s Algorithm</strong>
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

1. For the sake of discussion, let’s first make bold every other digit, starting with the number’s second-to-last digit:

<strong>4</strong> 0 <strong>0</strong> 3 <strong>6</strong> 0 <strong>0</strong> 0 <strong>0</strong> 0 <strong>0</strong> 0 <strong>0</strong> 0 <strong>1</strong> 4

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.

<strong>Implementation Details</strong>
In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

![image](https://github.com/user-attachments/assets/ca36f3d3-62a4-46ae-960c-995d3d2fbd5d)

Now, get_long itself will reject hyphens (and more) anyway:

![image](https://github.com/user-attachments/assets/ff7b2527-3bf4-41fd-be2b-4065acd398c3)

But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

![image](https://github.com/user-attachments/assets/4773ef80-60e1-45df-9cbd-565bad157eb5)

Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly will!) Here are a few card numbers that PayPal recommends for testing.

If your program behaves incorrectly on some inputs (or doesn’t compile at all), time to debug!
