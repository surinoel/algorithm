#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i0 = 1; i0 <= 3; i0++) {
			if (i0 == n) {
				ans += 1;
			}
			else if (i0 < n) {
				for (int i1 = 1; i1 <= 3; i1++) {
					if (i0 + i1 == n) {
						ans += 1;
					}
					else if (i0 + i1 < n) {
						for (int i2 = 1; i2 <= 3; i2++) {
							if (i0 + i1 + i2 == n) {
								ans += 1;
							}
							else if (i0 + i1 + i2 < n) {
								for (int i3 = 1; i3 <= 3; i3++) {
									if (i0 + i1 + i2 + i3 == n) {
										ans += 1;
									}
									else if (i0 + i1 + i2 + i3 < n) {
										for (int i4 = 1; i4 <= 3; i4++) {
											if (i0 + i1 + i2 + i3 + i4 == n) {
												ans += 1;
											}
											else if (i0 + i1 + i2 + i3 + i4 < n) {
												for (int i5 = 1; i5 <= 3; i5++) {
													if (i0 + i1 + i2 + i3 + i4 + i5 == n) {
														ans += 1;
													}
													else if (i0 + i1 + i2 + i3 + i4 + i5 < n) {
														for (int i6 = 1; i6 <= 3; i6++) {
															if (i0 + i1 + i2 + i3 + i4 + i5 + i6 == n) {
																ans += 1;
															}
															else if (i0 + i1 + i2 + i3 + i4 + i5 + i6 < n) {
																for (int i7 = 1; i7 <= 3; i7++) {
																	if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 == n) {
																		ans += 1;
																	}
																	else if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 < n) {
																		for (int i8 = 1; i8 <= 3; i8++) {
																			if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 == n) {
																				ans += 1;
																			}
																			else if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 < n) {
																				for (int i9 = 1; i9 <= 3; i9++) {
																					if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 == n) {
																						ans += 1;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
