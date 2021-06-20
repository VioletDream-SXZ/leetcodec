#ifndef __1600_H__
#define __1600_H__

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include "Solution.h"
#include "VectorUtils.h"

class ThroneInheritance : public Solution {
public:
    ThroneInheritance() = default;

    ~ThroneInheritance() = default;

    ThroneInheritance(string kingName) {
        mKingName = kingName; 
    }
    
    virtual void birth(string parentName, string childName) {
        // 多叉树的某一个边里面添加一个子树
        mEdges[std::move(parentName)].push_back(std::move(childName));
    }
    
    virtual void death(string name) {
        // 死亡列表里面添加对象
        mDeaths.insert(std::move(name));
    }
    
    virtual std::vector<string> getInheritanceOrder() {
        std::vector<std::string> result;
        // 递归添加根节点的儿子
        std::function<void(const std::string&, std::vector<std::string>&)> findInheritanceOrderVec = [&](const std::string& name, std::vector<std::string>& ans) {
            if (mDeaths.count(name) == 0) {
                ans.push_back(name);
            }

            if (mEdges.count(name)) {
                for (auto sonName: mEdges[name]) {
                    findInheritanceOrderVec(sonName, ans);
                }
            }
        };
        findInheritanceOrderVec(mKingName, result);
        return result;
    }

    virtual void run() {
        ThroneInheritance t = ThroneInheritance("king");
        t.birth("king", "andy");
        t.birth("king", "bob"); 
        t.birth("king", "catherine");
        t.birth("andy", "matthew");
        t.birth("bob", "alex"); 
        t.birth("bob", "asha"); 
        std::vector<std::string> result1 = t.getInheritanceOrder(); 
        t.death("bob"); 
        std::vector<std::string> result2 = t.getInheritanceOrder(); 
        Utils::display_int_vector(result1);
        Utils::display_int_vector(result2);
    }

public:
    std::unordered_map<std::string, std::vector<std::string>> mEdges;
    std::unordered_set<std::string> mDeaths;
    std::string mKingName;
};

#endif // __1600_H__