#!/usr/bin/env python3
# truncshop_automate_local.py
# Automates interactions with a local TruncShop process for testing only.
# WARNING: Do NOT use this script against remote servers you don't own.

import pexpect
import time

# Replace with the command used to launch your local copy of the challenge
COMMAND = "./truncshop_binary"  # <-- run your local executable here

# Example sequence for one profitable cycle:
# 1) Buy cake with coins
# 2) Sell cake for gems
# 3) Convert 2.99999999 gems
# Repeat as needed.

def run_cycle(child):
    # Main menu -> Buy Item (3)
    child.expect("Enter your choice \\(1-4\\):")
    child.sendline("3")
    child.expect("Enter item number")
    # Depending on your local menu ordering, change the item index for cake
    # This script assumes cake is option '3' in the menu like the provided session
    child.sendline("3")
    child.expect("Enter payment method \\(1-2\\):")
    child.sendline("1")  # pay with coins
    child.expect("Successfully purchased")
    # return to main menu prompt
    child.expect("Enter your choice \\(1-4\\):")
    # View Inventory -> Sell item
    child.sendline("1")
    child.expect("Enter your choice \\(1-2\\):")
    child.sendline("1")
    child.expect("Enter item number")
    child.sendline("1")  # sell the cake
    child.expect("Enter payment method \\(1-2, or 0 to cancel\\):")
    child.sendline("2")  # receive gems
    child.expect("Successfully sold")
    # return to main menu
    child.expect("Enter your choice \\(1-4\\):")
    # View Wallet -> Convert
    child.sendline("2")
    child.expect("Enter your choice \\(1-2\\):")
    child.sendline("1")
    child.expect("How many gems do you want to convert\\?:")
    child.sendline("2.99999999")
    child.expect("Converted")
    # wallet printed
    child.expect("Enter your choice \\(1-2\\):")
    child.sendline("2")  # return to main menu

def main():
    child = pexpect.spawn(COMMAND, encoding='utf-8', timeout=10)
    # Optionally log the interaction:
    child.logfile = open("truncshop_run.log", "w", encoding="utf-8")
    # wait for initial prompt
    child.expect("Enter your choice \\(1-4\\):")
    cycles = 60  # adjust how many cycles you want to run
    for i in range(cycles):
        print(f"Running cycle {i+1}/{cycles}")
        run_cycle(child)
        # small delay
        time.sleep(0.1)
    print("Done cycles. Check logfile truncshop_run.log and interact manually now.")
    child.interact()  # drop into interactive mode so you can finish manually

if __name__ == "__main__":
    main()