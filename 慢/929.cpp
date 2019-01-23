// 929 慢
#include <iostream>
#include <vector>
using namespace std;

bool check_duplicate(vector<string>& emails, string email) {
  for (vector<string>::iterator iter = emails.begin(); iter != emails.end(); iter ++) {
    if (email == *iter) return true;
  }
  return false;
}

string modify(string user) {
  string new_user;
  for (string::iterator iter = user.begin(); iter != user.end(); iter ++) {
    if (*iter == '.') continue;
    else if (*iter == '+') return new_user;
    else new_user.push_back(*iter);
  }
}

int numUniqueEmails(vector<string>& emails) {
  vector<string> actual_emails;
  int count = 0;
  for (vector<string>::iterator iter = emails.begin(); iter != emails.end(); iter ++) {
    cout << *iter << endl;
    string email = *iter;
    int flag = 0; // 0:@前，未遇到+；1:@前，已遇到+；2:@后
    int pos_at = email.find('@');
    string user = email.substr(0, pos_at);
    string tail = email.substr(pos_at);
    user = modify(user);
    string new_email = user.append(tail);
    bool dup = check_duplicate(actual_emails, new_email);
    if (dup) continue;
    else {
      actual_emails.push_back(new_email);
      count ++;
    }
  }
  return count;
}

int main () {
  vector <string> emails;
  emails.push_back("test.email+alex@leetcode.com");
  emails.push_back("test.e.mail+bob.cathy@leetcode.com");
  emails.push_back("testemail+david@lee.tcode.com");
  cout << numUniqueEmails(emails) << endl;
}