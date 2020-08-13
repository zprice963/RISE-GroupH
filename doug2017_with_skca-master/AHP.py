import numpy as np
from scipy.signal import find_peaks


def compute_AHP_stats(path: str) -> dict:
    """
    Returns a dictionary of various AHP statistics given a path to a .dat file.


    """

    lines = open(path, "r").readlines()[3:]
    n_elts = int(lines[0])

    T, V = [], []
    for i in range(1, n_elts):
        ln = lines[i]
        ln = ln.split()
        T.append(float(ln[0].strip()))
        V.append(float(ln[1].strip()))

    T = np.array(T)
    V = np.array(V)
    v_rest = V[0]

    ixs, props = find_peaks(-V, height=-v_rest)
    heights = -props["peak_heights"]

    X = v_rest - heights
    out = {}
    out["mean"] = np.mean(X)
    out["std"] = np.std(X)
    out["min"] = np.min(X)
    out["max"] = np.max(X)

    return out

path = 'vlPAG_DRN_Analysis.dat'
d = compute_AHP_stats(path)

print(d)
