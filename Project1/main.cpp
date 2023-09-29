#include "DialogueTree.h"

int main() {
	DataSource ds;
	ds.filename = "test_dialogue.csv";
	ds.columns = 4;
	ds.rows = 6;

	Tree t;
	t.Load(ds);

	t.ExecuteDialogue(t.root);

}