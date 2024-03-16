class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        for (string email : emails) {
            string local_name = email.substr(0, email.find('@'));
            string domain_name = email.substr(email.find('@') + 1);
            local_name.erase(remove(local_name.begin(), local_name.end(), '.'),
                             local_name.end());
            local_name = local_name.substr(0, local_name.find('+'));
            unique_emails.insert(local_name + '@' + domain_name);
        }
        return unique_emails.size();
    }
};