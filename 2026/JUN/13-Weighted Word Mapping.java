class Solution {
  public String mapWordWeights(String[] words, int[] weights) {
    String ans = "";

    int n = words.length;
    for (int i = 0; i < n; i++) {
      String word = words[i];
      int sum = 0;
      for (int j = 0; j < word.length(); j++) {
        int x = (int) word.charAt(j) - 'a';
        sum += weights[x];
      }
      int y = sum % 26;
      y = 26 - y - 1;
      ans += (char) (y + 'a');
    }

    return ans;
  }
}
