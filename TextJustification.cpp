class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            int j = i;
            int sumWidth = words[i].length();
            while (j + 1 < words.size() && sumWidth + 1 + words[j + 1].length() <= maxWidth) {
                j++;
                sumWidth += 1 + words[j].length();
            }
            string line(words[i]);
            int slots = j - i;
            if (slots == 0) {
                line.resize(maxWidth, ' ');
            } else {
                int slotSpace = (maxWidth - (sumWidth - slots)) / slots;
                if (j == words.size() - 1) {
                    for (int k = 1; k <= slots; k++) {
                        line += " " + words[i + k];
                    }
                    line.resize(maxWidth, ' ');
                } else {
                    int left = (maxWidth - (sumWidth - slots)) % slots;
                    for (int k = 1; k <= slots; k++) {
                        line += string(slotSpace, ' ');
                        if (k <= left) line += ' ';
                        line += words[i + k];
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};