#!/usr/bin/python3
""" Module for Prime Game  """


def is_prime(n):
    """ Solves Prime Game"""
    for a in range(2, int(n ** 0.5) + 1):
        if not n % a:
            return False
    return True


def add_prime(n, primes):
    """ Add prime to list """
    last_prime = primes[-1]
    if n > last_prime:
        for a in range(last_prime + 1, n + 1):
            if is_prime(a):
                primes.append(a)
            else:
                primes.append(0)


def isWinner(x, nums):
    """return None """
    score = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    add_prime(max(nums), primes)

    for round in range(x):
        _sum = sum((a != 0 and a <= nums[round])
                   for a in primes[:nums[round] + 1])
        if (_sum % 2):
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            score[winner] += 1

    if score["Maria"] > score["Ben"]:
        return "Maria"
    elif score["Ben"] > score["Maria"]:
        return "Ben"

    return None
