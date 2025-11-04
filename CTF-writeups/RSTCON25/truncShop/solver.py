
# truncshop_sim.py
# Local simulator & shortest-path finder for TruncShop-like rules (educational)

from collections import deque, namedtuple
from math import floor

State = namedtuple("State", ["coins_cents", "gems", "cake_qty"])
# we'll represent coins as integer cents to avoid floating errors
RATE = 300  # coins per gem in cents (3.00 coins = 300 cents)
CAKE_COST_CENTS = 800  # 8.00 coins
CAKE_SELL_GEMS = 3
CAKE_SELL_COINS_CENTS = 800  # alternative sell for coins if used

TARGET_COINS_CENTS = 10000  # 100.00 coins
TARGET_GEMS = 33

# Allowed actions:
# - buy_cake_with_coins (if coins >= 8.00)
# - sell_cake_for_gems (if cake_qty >=1)
# - convert_gems(x) where x is a positive float the player types
#   conversion model: gems_deducted = int(x)
#                     coins_added_cents = floor((x * RATE) + 1e-9) // keep floor to cents
#                     but we will floor to cents: floor(x*RATE)/1 -> in cents = floor(x*RATE)
#                     only allow conversion if gems >= gems_deducted and gems_deducted > 0

# For search we limit candidate x values to a useful discrete set derived from game:
# typical useful values: 1, 2, 2.99999999, 3, etc. We'll include:
CONVERT_INPUTS = [1.0, 2.0, 2.99999999, 3.0]  # extendable

def floor_to_cents(x_times_rate):
    # x_times_rate already in cents (RATE * x) -> floor it to int cents
    return int(x_times_rate + 1e-12)  # effectively floor

def neighbors(state):
    neigh = []
    # buy cake with coins
    if state.coins_cents >= CAKE_COST_CENTS:
        s = State(state.coins_cents - CAKE_COST_CENTS, state.gems, state.cake_qty + 1)
        neigh.append(("buy_cake_coins", None, s))
    # sell cake for gems
    if state.cake_qty >= 1:
        s = State(state.coins_cents, state.gems + CAKE_SELL_GEMS, state.cake_qty - 1)
        neigh.append(("sell_cake_for_gems", None, s))
    # sell cake for coins (optionally; we avoid to focus on gem route)
    if state.cake_qty >= 1:
        s2 = State(state.coins_cents + CAKE_SELL_COINS_CENTS, state.gems, state.cake_qty - 1)
        neigh.append(("sell_cake_for_coins", None, s2))
    # convert gems via candidate inputs
    for x in CONVERT_INPUTS:
        gems_deduct = int(x)  # truncation
        if gems_deduct <= 0:
            continue
        if state.gems >= gems_deduct:
            coins_add_cents = floor_to_cents(x * RATE)  # floor to cents
            s = State(state.coins_cents + coins_add_cents, state.gems - gems_deduct, state.cake_qty)
            neigh.append(("convert_gems", x, s))
    return neigh

def reached_target(state):
    return state.coins_cents >= TARGET_COINS_CENTS or state.gems >= TARGET_GEMS

def stringify_action(action):
    typ, val = action
    if typ == "buy_cake_coins":
        return "Buy cake (pay coins)"
    if typ == "sell_cake_for_gems":
        return "Sell cake (take gems)"
    if typ == "sell_cake_for_coins":
        return "Sell cake (take coins)"
    if typ == "convert_gems":
        return f"Convert {val} gems (user input {val})"
    return str(action)

def search_shortest():
    start = State(coins_cents=1000, gems=0, cake_qty=0)  # 10.00 coins = 1000 cents
    q = deque()
    q.append((start, []))
    seen = set()
    seen.add(start)
    while q:
        state, path = q.popleft()
        if reached_target(state):
            return state, path
        for action in neighbors(state):
            actname, val, next_state = action
            if next_state in seen:
                continue
            seen.add(next_state)
            q.append((next_state, path + [(actname, val, next_state)]))
    return None, None

if __name__ == "__main__":
    final_state, path = search_shortest()
    if not path:
        print("No path found with given moveset.")
    else:
        print("Found path to target!")
        print("Final state:", final_state)
        print("Steps:")
        st = State(1000,0,0)
        print(f"Start: Coins={st.coins_cents/100:.2f}, Gems={st.gems}, Cake={st.cake_qty}")
        for i,(act,val,s) in enumerate(path,1):
            print(f"{i:2d}. {stringify_action((act,val))}")
            print(f"    -> Coins={s.coins_cents/100:.2f}, Gems={s.gems}, Cake={s.cake_qty}")
        print("\nSummary:")
        print(f"Total steps: {len(path)}")
        print(f"End: Coins={final_state.coins_cents/100:.2f}, Gems={final_state.gems}, Cake={final_state.cake_qty}")
