#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{};
	vvi tri_{};
	vvi dp_{};
	int ans_{};

public:
	void input() {
		cin >> n_;

		tri_ = vvi(n_);
		for (auto i = 0; i < n_; ++i) {
			tri_[i] = vi(i + 1);
			for (auto j = 0; j <= i; ++j) {
				cin >> tri_[i][j];
			}
		}
	}

	void solve() {
		ans_ = 0;

		dp_ = vvi(n_);
		for (auto i = 0; i < n_; ++i) {
			dp_[i] = vi(i + 1, -1);
		}

		dp_[0][0] = tri_[0][0];
		ans_ = dp_[0][0];
		part(1);
	}

	void output() const noexcept {
		cout << ans_;
	}

private:
	void part(int y) {
		if (n_ == y) {
			return;
		}

		for (auto x = 0; x <= y; ++x) {
			if (0 == x) {
				dp_[y][x] = dp_[y - 1][x] + tri_[y][x];
			}
			else if (y == x) {
				dp_[y][x] = dp_[y - 1][x - 1] + tri_[y][x];
			}
			else {
				const auto& s1 = dp_[y - 1][x - 1] + tri_[y][x];
				const auto& s2 = dp_[y - 1][x] + tri_[y][x];

				dp_[y][x] = max(s1, s2);
			}

			if (ans_ < dp_[y][x]) {
				ans_ = dp_[y][x];
			}
		}

		part(y + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution{};
	s.input();
	s.solve();
	s.output();

	return 0;
}