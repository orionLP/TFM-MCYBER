"""
Kaplan-Meier survival estimator plotting.

Each dataset is defined by:
    n0      : starting number of samples at t=0
    deaths  : list of length T, deaths[i-1] = number of samples that died
              at timestep i (i = 1..T). T is arbitrary per dataset.

S(0) = 1 by definition.
For t = 1..T:
    n_t = n0 - sum(deaths[0:t-1])   (number at risk just before t)
    S(t) = S(t-1) * (1 - deaths[t-1] / n_t)
"""

import matplotlib.pyplot as plt


def kaplan_meier(n0: int, deaths: list[int]) -> list[float]:
    """Return S(t) for t = 0..len(deaths), S[0] = S(0) = 1."""
    S = [1.0]
    n_at_risk = n0
    for d in deaths:
        if n_at_risk <= 0:
            S.append(S[-1])
            continue
        S.append(S[-1] * (1 - d / n_at_risk))
        n_at_risk -= d
    for i in range(len(S)):
        if S[i] <= 0:
            S[i] = 0.0
    return S

def plot_km(datasets: dict[str, dict]):
    """
    datasets: {name: {"n0": int, "deaths": [int, ...]}}
    One figure per dataset, step plot of S(t).
    """
    for name, data in datasets.items():
        n0 = data["n0"]
        deaths = data["deaths"]
        S = kaplan_meier(n0, deaths)
        t = list(range(len(S)))

        fig, ax = plt.subplots()
        ax.step(t, S, where="post")
        ax.set_title(f"Kaplan-Meier Estimate — {name}")
        ax.set_xlabel("t")
        ax.set_ylabel(r"$\hat{S}(t)$")
        ax.set_ylim(0, 1.05)
        ax.set_xticks(t)
        ax.grid(True, alpha=0.3)
        fig.tight_layout()

    plt.show()


if __name__ == "__main__":
    # Example usage
    datasets = {
        "Code obfuscation": {"n0": 15, "deaths": [1, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]},
    }
    plot_km(datasets)
