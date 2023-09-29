#include "DialogueTree.h"

int main() {
	DataSource ds;
	ds.filename = "test_dialogue.tsv";
	ds.columns = 4;
	ds.rows = 6;

	Tree t;
	t.Load(ds);

	t.ExecuteDialogue(t.root);

}