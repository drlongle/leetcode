/*
Determine the coordinate and move there. Note that 'z' is tricky as you cannot move left or right in the last row.
To account for that, make sure we move up before moving right, and move left before moving down.
*/

string alphabetBoardPath(string target, int x = 0, int y = 0) {
  string res;
  for (auto ch : target) {
    int x1 = (ch - 'a') % 5, y1 = (ch - 'a') / 5;
    res += string(max(0, y - y1), 'U') + string(max(0, x1 - x), 'R') +
      string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D') + "!";
    x = x1, y = y1;
  }
  return res;
}

