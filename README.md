Password Utility

Language: C | Author: Richard Dzreke

A simple password analysis tool that:

Estimates password strength in bits (entropy).

Checks passwords against a list of 10,000 common passwords (10k).

Normalizes leet-style passwords before checking (l33t).

Performs “plus1” checks by removing the last character.

Usage:

./password_util <command> <password>


Example:

./password_util entropy P@ssw0rd
bits of entropy: 62


Commands: 10k, l33t, plus1, entropy
