

/********
Dated : 22/02/15
This code Belongs to Jayanth Prakash Kulkarni
CSE 4th Semester BTech,
M.S.Ramaiah Institute of Technology,Bangalore.
********/



#include <iostream>
#define MAX 3
#define FOR(i,j) for(int i=0;i<j;i++)
using namespace std;

typedef struct match
{
	int preference[MAX][MAX];
	int flag[MAX];
	int matched[MAX];
	int currentpreference[MAX];
	int current_women_index[MAX];//man's current woman index
}match;

void init_preference(match &m, match &w)
{
	cout << "Enter the preference of the men!" << endl;
	FOR(i, MAX)
	{
		cout << "Preference of man " << i + 1 << endl;
		m.flag[i] = 0;
		m.current_women_index[i] = 0;
		FOR(j, MAX)
		{
			cin >> m.preference[i][j];

		}
	}

	cout << "Enter the preference of the women! " << endl;
	FOR(i, MAX)
	{
		cout << "Preference of woman " << i + 1 << endl;
		w.flag[i] = -1;
		FOR(j, MAX)
		{
			cin >> w.preference[i][j];
		}
	}
}

void disp_match(match &m)
{
	cout << "\n\n";
	FOR(i, MAX)
	{
		FOR(j, MAX)
		{
			cout << m.preference[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void perform_match(match &m, match &w)
{
	int co;
	int i = 0;
	int j = 0;//ith man's current woman index
	int overall_flag=0;

	while ((i<MAX) && m.flag[i] == 0||(overall_flag<3))
	{
		while (i<MAX && m.flag[i] == 0)
		{
			if (overall_flag < 3)
			{
				int num;
				int current_woman = m.preference[i][m.current_women_index[i]];
				int current_man = i;
				if (w.flag[current_woman] == -1)//woman is free
				{
					m.matched[i] = current_woman;
					m.flag[i] = 1;//he is engaged
					w.currentpreference[current_woman] = i;
					w.flag[current_woman] = 1;//she is engaged
				}
				else //woman is already engaged
				{
					int old_man_index;
					int old_man = w.currentpreference[current_woman];//index of the already preferred one
					FOR(i, MAX)
					{
						if (w.preference[current_woman][i] == current_man)//
						{
							num = i;

						}
						if (w.preference[current_woman][i] == old_man)
						{
							old_man_index = i;
						}
					}
					if (num<old_man_index)
					{
						m.flag[old_man] = 0;
						m.flag[current_man] = 1;
						m.matched[current_man] = current_woman;
						w.currentpreference[current_woman] = current_man;
						i = old_man;
						m.current_women_index[i]++;
						j = m.current_women_index[i];
						overall_flag = 0;
						FOR(j, MAX)
						{
							if (m.flag[j])
								overall_flag++;
						}
						continue;
					}
					else
					{
						i = old_man;
						m.current_women_index[i]++;
						j = m.current_women_index[i];
						overall_flag = 0;
						FOR(j, MAX)
						{
							if (m.flag[j])
								overall_flag++;
						}
						continue;
					}
				}
				overall_flag = 0;
				FOR(j, MAX)
				{
					if (m.flag[j])
						overall_flag++;
				}

				 i++;
				 co = i;
			}
		}
		i = co;
		i++;

	}
}
void display_result(match &m)
{
	FOR(i, MAX)
	{
		cout << "Man" << i << " is mapped with " << m.matched[i] << endl;
	}
	cin.clear();
	cin.ignore();
}

int main()
{
	match men, women;
	init_preference(men, women);
	disp_match(men);
	disp_match(women);
	perform_match(men, women);
	display_result(men);
	cin.clear();
	cin.ignore();
	return 0;

}
