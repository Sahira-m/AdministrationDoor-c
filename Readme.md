This is the administration part for an entry system where the visitor scans their card.

Remote open door

When you select this, the system should open the door, "shown" by a GREEN light .

The door must be open (green light) for 3 seconds

List all cards in system

List ALL card numbers and write if they have access or NOT

(1212 have access, 1213 have been denied and DATE when they were added to the system)

Cards should possibly be created here if they do not already exist.

So there is a light on the card unit. It will shine

RED: when you have scanned a card that does not have access

GREEN: when you have scanned a card that has access

But we are faking it by printing “CURRENTLY LAMP IS: Green” and Red

Hints:-

- buffer overflow (input)
- stack overflow (flow)
- divide into functions
- no global variables

- collect "state" in STRUCT

- don't crash on BAD input

- error handling, kind to the user

- the system must handle "UNLIMITED" number of cards (dynamic memory allocation - mallloc/realloc)

Insructions:
Cards must be SAVED in FILE! In other words, after restarting, all cards must be read out and remain

Branch with alternative implementation: make a version WITHOUT dynamic memory allocation (and no static array either...but you should still manage "infinitely" many cards !). That means you get to read ONE AT A TIME

all the time from file, more info https://youtu.be/GqKZFzM9COA

Good code, best practices, etc
