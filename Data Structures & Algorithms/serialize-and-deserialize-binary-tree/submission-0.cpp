class Codec {
public:

    // SERIALIZE: Level Order
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(currNode->val) + ",");
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }

        return s;
    }

    // DESERIALIZE: Level Order
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // LEFT CHILD
            if (!getline(ss, val, ',')) break;
            if (val == "#") {
                curr->left = NULL;
            } else {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }

            // RIGHT CHILD
            if (!getline(ss, val, ',')) break;
            if (val == "#") {
                curr->right = NULL;
            } else {
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }

        return root;
    }
};
