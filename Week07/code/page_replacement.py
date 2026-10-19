#!/usr/bin/env python3
"""page_replacement.py -- simulate FIFO, OPT and LRU page replacement.
Prints the frame contents after every reference (F = fault) and the
number of page faults. Also checks Belady's anomaly and the EAT example.
Run:  python3 page_replacement.py
"""

def simulate(refs, nframes, policy):
    frames, faults, rows = [], 0, []
    queue = []            # FIFO: order of arrival
    last_use = {}         # LRU: time of last use
    for t, p in enumerate(refs):
        fault = p not in frames
        if fault:
            faults += 1
            if len(frames) < nframes:           # a free frame exists
                frames.append(p)
            else:                                # choose a victim
                if policy == "FIFO":
                    victim = queue.pop(0)
                elif policy == "LRU":
                    victim = min(frames, key=lambda q: last_use[q])
                elif policy == "OPT":            # used farthest in the future
                    def next_use(q):
                        rest = refs[t + 1:]
                        return rest.index(q) if q in rest else float("inf")
                    victim = max(frames, key=next_use)
                frames[frames.index(victim)] = p   # same slot
            if policy == "FIFO":
                queue.append(p)
        last_use[p] = t
        rows.append((p, list(frames), fault))
    return faults, rows

def show(refs, n, policy, tag=""):
    faults, rows = simulate(refs, n, policy)
    print(f"{tag}{policy}, {n} frames: {faults} page faults")
    print("ref   " + " ".join(f"{p:>2}" for p, _, _ in rows))
    for k in range(n):
        line = []
        for _, fr, _ in rows:
            line.append(f"{fr[k]:>2}" if k < len(fr) else " .")
        print(f"fr{k}   " + " ".join(line))
    print("fault " + " ".join(" F" if f else "  " for _, _, f in rows))
    print()
    return faults

refs = [7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1]
for pol in ("FIFO", "OPT", "LRU"):
    show(refs, 3, pol)

belady = [1,2,3,4,1,2,5,1,2,3,4,5]
for n in (3, 4):
    show(belady, n, "FIFO", tag="Belady: ")
for n in (3, 4):                    # LRU is a stack algorithm: no anomaly
    print(f"Belady string, LRU {n} frames: {simulate(belady, n, 'LRU')[0]} faults")
print()

# Effective access time with page faults
tm, tf = 200e-9, 8e-3
for p in (0.001,):
    eat = (1 - p) * tm + p * tf
    print(f"EAT(p={p}) = {eat*1e9:.1f} ns = {eat*1e6:.3f} us, slowdown x{eat/tm:.1f}")
pmax = (0.1 * tm) / (tf - tm)       # (1-p)tm + p tf < 1.1 tm
print(f"slowdown < 10%  =>  p < {pmax:.3e}  (1 fault per {1/pmax:,.0f} accesses)")
print()

# Working set with window DELTA (last DELTA references up to time t)
ws_refs = [2,6,1,5,7,7,7,7,5,1,6,2,3,4,1,2,3,4,4,4,3,4,3,4,4,4]
DELTA = 10
for t in (9, 25):                   # 0-based positions t1 and t2
    window = ws_refs[t - DELTA + 1:t + 1]
    print(f"WS(t={t+1}) window {window} -> {sorted(set(window))}, WSS={len(set(window))}")
