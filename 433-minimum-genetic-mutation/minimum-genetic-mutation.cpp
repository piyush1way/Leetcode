class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end())
            return -1;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        string chars = "ACGT";

        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();

            if (gene == endGene)
                return steps;

            for (int i = 0; i < gene.size(); ++i) {
                char original = gene[i];
                for (char c : chars) {
                    if (c == original)
                        continue;
                    gene[i] = c;
                    if (bankSet.count(gene) && !visited.count(gene)) {
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = original; // restore
            }
        }

        return -1;
    }
};