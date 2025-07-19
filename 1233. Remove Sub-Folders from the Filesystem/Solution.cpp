#include <vector>
#include <string>
#include <algorithm>

class Solution {
   public:

    bool isSubfolder(const std::string& parent, const std::string& child) {
        return child.find(parent + "/", 0) == 0;
    }

    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        std::sort(folder.begin(), folder.end());

        std::vector<std::string> result;
        if (folder.empty()) {
            return result;
        }

        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); ++i) {
            const std::string& currentFolder = folder[i];
            const std::string& lastAddedFolder = result.back();

            if (!isSubfolder(lastAddedFolder, currentFolder)) {
                result.push_back(currentFolder);
            }
        }
        return result;
    }
};
