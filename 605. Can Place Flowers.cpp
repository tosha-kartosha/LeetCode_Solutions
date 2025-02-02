class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len_flower = flowerbed.size();
        int all_pos_flowers = 0;
        if (std::count(flowerbed.begin(), flowerbed.end(), 0) == len_flower) {
            all_pos_flowers = len_flower % 2 == 0 ? len_flower / 2 : (len_flower / 2) + 1;
            return all_pos_flowers >= n ? true : false;
        }
        int num_z = 0;
        bool left_side = false;
        if (flowerbed[0] == 0) {
            num_z = 1;
            left_side = true;
        }
        for (int i = 1; i < len_flower; ++i) {
            if (flowerbed[i] == 0) {
                num_z += 1;
            }
            else {
                if (left_side) {
                    all_pos_flowers += num_z / 2;
                } else {
                    all_pos_flowers += num_z % 2 != 0 ? num_z / 2 : (num_z / 2) - 1;
                }
                left_side = false;
                num_z = 0;
            }
        }
        if (flowerbed[len_flower-1] == 0) {
            all_pos_flowers += num_z / 2;
        }
        return all_pos_flowers >= n ? true : false;
    }
};
