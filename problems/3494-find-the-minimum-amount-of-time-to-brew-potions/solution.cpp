// 3494. Find the Minimum Amount of Time to Brew Potions [Medium]
// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/
// Language: C++ | Runtime: 147 ms | Memory: 44.5 MB

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long sumSkill = accumulate(skill.begin(), skill.end(), 0L);
        // prevWizardDone stores the finish time of wizard 0 after processing up to the previous potion
        long prevWizardDone = sumSkill * (long)mana[0];

        for (int j = 1; j < (int)mana.size(); ++j) {
            long prevPotionDone = prevWizardDone;
            // iterate wizards from second-last down to 0 to compute constraints
            for (int i = (int)skill.size() - 2; i >= 0; --i) {
                // remove the time contributed by wizard i+1 on previous potion from prevPotionDone
                prevPotionDone -= (long)skill[i + 1] * (long)mana[j - 1];

                // For wizard i, when adding potion j, ensure it's not earlier than
                // the time wizard i+1 finished the previous chain (prevPotionDone),
                // and also respect the previous prevWizardDone offset minus wizard i's new time.
                prevWizardDone = max(prevPotionDone,
                                     prevWizardDone - (long)skill[i] * (long)mana[j]);
            }
            // finally add the full column contribution (sumSkill * mana[j])
            prevWizardDone += sumSkill * (long)mana[j];
        }
        return prevWizardDone;
    }
};
