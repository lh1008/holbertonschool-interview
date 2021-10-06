# 0x22. Prime Game

### Tasks

_**0. Prime Game**_
Given a set of consecutive integers starting from `1` up to and including `n`, some numbers will be sent in rounds where each round will have specific instructions of what the participants will do. `x` round will be played, where `n` will be different in every round.

First round: `4`

- Maria picks 2 and removes 2, 4, leaving 1, 3
- Ben picks 3 and removes 3, leaving 1
- Ben wins because there are no prime numbers left for Maria to choose

Second round: `5`

- Maria picks 2 and removes 2, 4, leaving 1, 3, 5
- Ben picks 3 and removes 3, leaving 1, 5
- Maria picks 5 and removes 5, leaving 1
- Maria wins because there are no prime numbers left for Ben to choose

Third round: `1`

- Ben wins because there are no prime numbers for Maria to choose
