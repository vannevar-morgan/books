// ************************************************************
//              Name:  vann
//          Filename:  problem.16.1.cpp
//           Project:  --project name--
//       
//      Date written:  Tuesday, November 15, 2016
//
//     --Code Summary--
// "Write a self-reproducing program.  Such a program is one 
//  that does no input, and that, when run, writes a copy of
//  its own source text on the standard output stream."
//
// (What the problem is describing is a quine)
// https://en.wikipedia.org/wiki/Quine_(computing)
// ************************************************************

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(void){
  string src_text[] = {"// ************************************************************\n//              Name:  vann\n//          Filename:  problem.16.1.cpp\n//           Project:  --project name--\n//       \n//      Date written:  Tuesday, November 15, 2016\n//\n//     --Code Summary--\n// \"Write a self-reproducing program.  Such a program is one \n//  that does no input, and that, when run, writes a copy of\n//  its own source text on the standard output stream.\"\n//\n// (What the problem is describing is a quine)\n// https://en.wikipedia.org/wiki/Quine_(computing)\n// ************************************************************\n\n#include <iostream>\n#include <string>\n#include <vector>\n\nusing namespace std;\n\n\nint main(void){\n  string src_text[] = {", R"(// ************************************************************\n//              Name:  vann\n//          Filename:  problem.16.1.cpp\n//           Project:  --project name--\n//       \n//      Date written:  Tuesday, November 15, 2016\n//\n//     --Code Summary--\n// \"Write a self-reproducing program.  Such a program is one \n//  that does no input, and that, when run, writes a copy of\n//  its own source text on the standard output stream.\"\n//\n// (What the problem is describing is a quine)\n// https://en.wikipedia.org/wiki/Quine_(computing)\n// ************************************************************\n\n#include <iostream>\n#include <string>\n#include <vector>\n\nusing namespace std;\n\n\nint main(void){\n  string src_text[] = {)", "};\n\n  cout << src_text[0];\n  cout << \"\\\"\" << src_text[1] << \"\\\", R\\\"(\" << src_text[1] << \")\\\", \";\n  cout << \"\\\"\" << src_text[3] << \"\\\", R\\\"(\" << src_text[3] << \")\\\"\";\n  cout << src_text[2];\n  cout << endl;\n  return 0;\n}", R"(};\n\n  cout << src_text[0];\n  cout << \"\\\"\" << src_text[1] << \"\\\", R\\\"(\" << src_text[1] << \")\\\", \";\n  cout << \"\\\"\" << src_text[3] << \"\\\", R\\\"(\" << src_text[3] << \")\\\"\";\n  cout << src_text[2];\n  cout << endl;\n  return 0;\n})"};

  cout << src_text[0];
  cout << "\"" << src_text[1] << "\", R\"(" << src_text[1] << ")\", ";
  cout << "\"" << src_text[3] << "\", R\"(" << src_text[3] << ")\"";
  cout << src_text[2];
  cout << endl;
  return 0;
}
