// 1948. Delete Duplicate Folders in System [Hard]
// https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Language: C++ | Runtime: 197 ms | Memory: 270.2 MB

class Solution {
public:
    struct Trie {
        string name;
        unordered_map<string, Trie*> children;
        bool deleted = false;
    };

    Trie* root = new Trie();

    // Step 1: Build the Trie
    void insert(const vector<string>& path) {
        Trie* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new Trie();
                node->children[folder]->name = folder;
            }
            node = node->children[folder];
        }
    }

    // Step 2: Serialize the Trie subtrees and store them
    string serialize(Trie* node, unordered_map<string, vector<Trie*>>& seen) {
        if (node->children.empty()) return "";

        vector<string> serials;
        for (auto& [name, child] : node->children) {
            string s = serialize(child, seen);
            serials.push_back("(" + s + name + ")");
        }

        sort(serials.begin(), serials.end());
        string combined;
        for (string& s : serials) combined += s;

        seen[combined].push_back(node);
        return combined;
    }

    // Step 3: DFS to gather remaining folders
    void collect(Trie* node, vector<string>& path, vector<vector<string>>& result) {
        if (node->deleted) return;
        if (!node->name.empty()) path.push_back(node->name);
        if (!path.empty()) result.push_back(path);

        for (auto& [name, child] : node->children) {
            collect(child, path, result);
        }

        if (!node->name.empty()) path.pop_back();
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Build the Trie
        for (auto& path : paths) insert(path);

        // Detect duplicate subtrees
        unordered_map<string, vector<Trie*>> seen;
        serialize(root, seen);

        for (auto& [key, nodes] : seen) {
            if (nodes.size() > 1) {
                for (Trie* node : nodes) {
                    node->deleted = true;
                }
            }
        }

        // Collect remaining folders
        vector<vector<string>> result;
        vector<string> current;
        for (auto& [name, child] : root->children) {
            collect(child, current, result);
        }

        return result;
    }
};
