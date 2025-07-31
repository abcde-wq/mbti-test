#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Question {
public:
    string text;
    char optionAType;
    char optionBType;
    string optionA;
    string optionB;

    Question(string t, char aType, char bType, string a, string b) :
        text(t), optionAType(aType), optionBType(bType), optionA(a), optionB(b) {
    }
};

void set_quiz(vector<Question>& questions) {
    // E vs I
    questions.push_back(Question("Q1. パーティーでは：", 'E', 'I', "多くの人と交流する", "少数の人と深く話す"));
    questions.push_back(Question("Q2. 会話の中で：", 'E', 'I', "多く話す", "多く聞く"));
    questions.push_back(Question("Q3. 休日の過ごし方：", 'E', 'I', "外出して活動的に過ごす", "家でゆっくり過ごす"));
  
    // S vs N
    questions.push_back(Question("Q4. 新しい情報を理解する際：", 'S', 'N', "具体的な事実や詳細に注目する", "全体的な概念や可能性を考える"));
    questions.push_back(Question("Q5. 本を読む時に好むのは：", 'S', 'N', "現実的で実用的な内容", "想像力豊かでアイデア的な内容"));
    questions.push_back(Question("Q6. 興味を引かれるのは：", 'S', 'N', "具体的で現実的なもの", "抽象的で理論的なもの"));
    
    // T vs F
    questions.push_back(Question("Q7. 決断を下す時：", 'T', 'F', "論理的に分析する", "感情や価値観を重視する"));
    questions.push_back(Question("Q8. 問題解決時：", 'T', 'F', "客観的な事実を重視する", "人々への影響を考慮する"));
    questions.push_back(Question("Q9. 人を評価する際：", 'T', 'F', "能力や実績を重視する", "性格や人間性を重視する"));
   
    // J vs P
    questions.push_back(Question("Q10. 計画を立てる際：", 'J', 'P', "詳細まで決めておく", "柔軟性を持たせる"));
    questions.push_back(Question("Q11. 仕事の進め方：", 'J', 'P', "計画通りに進める", "状況に応じて調整する"));
    questions.push_back(Question("Q12. 締め切りに対して：", 'J', 'P', "余裕を持って計画的に進める", "ギリギリまで待ってから集中する"));
}

char ask_question(const Question& q) {
    cout << q.text << endl;
    cout << "A: " << q.optionA << endl;
    cout << "B: " << q.optionB << endl;
    cout << ">> ";

    char input;
    cin >> input;
    input = toupper(input);

    while (input != 'A' && input != 'B') {
        cout << "AかBを入力してください: ";
        cin >> input;
        input = toupper(input);
    }

    return (input == 'A') ? q.optionAType : q.optionBType;
}

void run_mbti() {
    vector<Question> questions;
    set_quiz(questions);

    map<char, int> scores = {
        {'E', 0}, {'I', 0},
        {'S', 0}, {'N', 0},
        {'T', 0}, {'F', 0},
        {'J', 0}, {'P', 0}
    };

    for (auto& q : questions) {
        char ans = ask_question(q);
        scores[ans]++;
        cout << endl;
    }

    string result = "";
    result += (scores['E'] >= scores['I']) ? 'E' : 'I';
    result += (scores['S'] >= scores['N']) ? 'S' : 'N';
    result += (scores['T'] >= scores['F']) ? 'T' : 'F';
    result += (scores['J'] >= scores['P']) ? 'J' : 'P';

    cout << "あなたのMBTIタイプは: " << result << " です。" << endl;
}

int main() {
    cout << "MBTI 16タイプ診断を開始します。\n";
    run_mbti();
    return 0;
}
