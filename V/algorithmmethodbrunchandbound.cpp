#include "algorithmmethodbrunchandbound.h"


struct inf
{
    unsigned int i = std::numeric_limits<unsigned int>::max();
};
struct inf myinf;
struct Node
{
    short unsigned size = 0;
    unsigned int cost = 0;
    std::pair<std::pair<unsigned short, unsigned short>, unsigned int>** matrix = NULL;
    struct Node* lnode = NULL;
    struct Node* rnode = NULL;
    vector<pair<short unsigned, short unsigned>> way;
};

void matrixInitialization(struct Node*& head,std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix, unsigned short int size)
{
    head->size = size;
    head->matrix = new pair<pair<unsigned short, unsigned short>, unsigned int>* [head->size];

    for (unsigned short i = 0; i < head->size; ++i)
    {
        head->matrix[i] = new pair<pair<unsigned short, unsigned short>, unsigned int>[head->size];
        for (unsigned short j = 0; j < head->size; ++j)
        {
            if (i != j) head->matrix[i][j].second = matrix[i][j].second;
            else head->matrix[i][j].second = myinf.i;

            head->matrix[i][j].first.first = matrix[i][j].first.first;
            head->matrix[i][j].first.second = matrix[i][j].first.second;
        }
    }
}

void print(struct Node*& node, string information, QTextBrowser *browser)
{
    QString s, t;
    browser->append("--------------------------------------------------------------------------------\n\n");
    browser->append("information:\t" + (QString)information.c_str() + "\nCost:\t" + s.setNum(node->cost) + "\nWay:\t");
    if ((node->way).size())
    {
        for (unsigned short i = 0; i < (node->way).size(); ++i)
            browser->append("(" + s.setNum((node->way)[i].first + 1) + " ; " + t.setNum((node->way)[i].second + 1) + ")");
    }
    else browser->append("\nWay is empty!\n");

//    browser->append("Coordinates in rows and columns:\n");
//    for (unsigned short i = 0; i < node->size; ++i)
//        browser->append("(" + s.setNum((node->matrix)[i][0].first.first + 1) + " ; " + s.setNum((node->matrix)[0][i].first.second + 1) + ")");
//    browser->append("\nMatrix:\n");

//    for (unsigned short i = 0; i < node->size; ++i)
//    {
//        for (unsigned short j = 0; j < node->size; ++j)
//        {
//            if ((node->matrix)[i][j].second != myinf.i)
//                browser->append(s.setNum((node->matrix)[i][j].second) + "  ");
//            else browser->append("inf  ");
//        }
//        browser->append("\n)");
//    }
//    browser->append("\n\n********************************************************************************\n");
}

unsigned castRows(struct Node*& node)
{
    unsigned min = myinf.i, sum = 0;

    for (unsigned short i = 0; i < node->size; ++i)
    {
        min = myinf.i;
        for (unsigned short j = 0; j < node->size; ++j)
        {
            if (min > (node->matrix)[i][j].second)
                min = (node->matrix)[i][j].second;
        }
        for (unsigned short j = 0; j < node->size; ++j)
        {
            if ((node->matrix)[i][j].second != myinf.i)
                (node->matrix)[i][j].second -= min;
        }
        sum += min;
    }
    return sum;
}

unsigned castColumns(struct Node*& node)
{
    unsigned min = myinf.i, sum = 0;

    for (unsigned short i = 0; i < node->size; ++i)
    {
        min = myinf.i;
        for (unsigned short j = 0; j < node->size; ++j)
        {
            if (min > (node->matrix)[j][i].second)
                min = (node->matrix)[j][i].second;
        }
        for (unsigned short j = 0; j < node->size; ++j)
        {
            if ((node->matrix)[j][i].second != myinf.i)
                (node->matrix)[j][i].second -= min;
        }
        sum += min;
    }
    return sum;
}

tuple<unsigned, pair<unsigned short, unsigned short>> penalty(struct Node* node)
{
    pair<unsigned short, unsigned short> imax_penalty;
    unsigned max_penalty = 0, min_in_column, min_in_row;

    for (unsigned short i = 0; i < node->size; ++i)
    {
        min_in_column = min_in_row = myinf.i;
        for (unsigned short j = 0; j < node->size; ++j)
        {
            if ((node->matrix)[i][j].second == 0)
            {
                //в строке минимум
                for (unsigned short k = 0; k < node->size; ++k)
                {
                    if ((node->matrix)[i][k].second < min_in_row && k != j)
                    {
                        min_in_row = (node->matrix)[i][k].second;
                    }
                }
                //в столбце минимум
                for (unsigned short k = 0; k < node->size; ++k)
                {
                    if ((node->matrix)[k][j].second < min_in_column && k != i)
                    {
                        min_in_column = (node->matrix)[k][j].second;
                    }
                }

                if (max_penalty < min_in_row + min_in_column && min_in_row != myinf.i && min_in_column != myinf.i)
                {
                    max_penalty = min_in_row + min_in_column;
                    imax_penalty = make_pair((node->matrix)[i][j].first.first, (node->matrix)[i][j].first.second);
                }
            }
        }
    }
    return tie(max_penalty, imax_penalty);
}

void copyLeftNode(struct Node*& node1, struct Node*& node2)
{
    node2->size = node1->size;
    node2->cost += node1->cost;
    node2->way = node1->way;

    node2->matrix = new pair<pair<unsigned short, unsigned short>, unsigned int>* [node2->size];
    for (short unsigned i = 0; i < node1->size; ++i)
    {
        (node2->matrix)[i] = new pair<pair<unsigned short, unsigned short>, unsigned int>[node2->size];
        for (short unsigned j = 0; j < node1->size; ++j)
            (node2->matrix)[i][j] = (node1->matrix)[i][j];
    }
};

void copyRightNode(struct Node*& node1, struct Node*& node2, pair<short unsigned, short unsigned> rib)
{
    short unsigned ishift = 0, jshift = 0;
    node2->size = node1->size - 1;
    node2->matrix = new pair<pair<unsigned short, unsigned short>, unsigned int>* [node2->size];
    node2->cost += node1->cost;
    node2->way = node1->way;
    (node2->way).push_back(rib);

    for (unsigned int i = 0; i < node1->size; ++i)
    {
        (node2->matrix)[i] = new pair<pair<unsigned short, unsigned short>, unsigned int>[node2->size];
        if ((node1->matrix)[i][0].first.first != rib.first)
        {
            for (unsigned int j = 0; j < node1->size; ++j)
            {
                if ((node1->matrix)[i][j].first.second != rib.second) (node2->matrix)[i - ishift][j - jshift] = (node1->matrix)[i][j];
                else jshift = 1;
            }
            jshift = 0;
        }
        else ishift = 1;
    }
};

void runProgram(std::pair<std::pair<unsigned short,  unsigned short>, unsigned>** matrix, unsigned short int size, QTextBrowser* browser)
{
    Node* head = new Node;
    matrixInitialization(head, matrix, size);
    Node* chead = head;
    set <Node*> lists;
    unsigned cast_function = 0;
    pair<short unsigned, short unsigned> rib;
    unsigned int steps = 0;

    while (chead->size > 2)
    {
        ++steps;
        //создаем левую ветку и правую и их присваиваем вершине
        Node* lnode = new Node;
        Node* rnode = new Node;
        chead->lnode = lnode;
        chead->rnode = rnode;
        //------------------------------------------------------------------

        //Добавляем элементы в множество листьев и удаляем из него их вершину
        lists.insert(lnode);
        lists.insert(rnode);
        lists.erase(chead);
        //Print(chead, "Current penalty before:");
        //-------------------------------------------------------------------
        copyLeftNode(chead, lnode);
        //Приводим матрицу из узла вершины по строкам а потом по столбцам
        cast_function += castRows(chead);
        cast_function += castColumns(chead);
        //-------------------------------------------------------------------

        //прибавляем стоимость приведения текущей вершине
        //копируем в левую ветвь
        chead->cost += cast_function;
        lnode->cost += cast_function;// добавлено от 1
        cast_function = 0;
        //-------------------------------------------------------------------
        //Функция штрафа. Прибавляем cast_function к cost и убираем из возможных путей (irib; jrib)
        tie(cast_function, rib) = penalty(chead);
//        cout << endl << endl << endl << "Current penalty:\t" << cast_function << endl  << rib.first << " " << rib.second << endl << endl << endl;
        lnode->cost += cast_function;
        pair<unsigned short, unsigned short> help = findCurrentMatrixIndex(lnode, rib);
        (lnode->matrix)[help.first][help.second].second = myinf.i;
        cast_function = 0;
        //-------------------------------------------------------------------
        //Копируем правую ветвь и приводим по строкам и столбцам
        copyRightNode(chead, rnode, rib);
        //-------------------------------------------------------------------
        //Исключаем досрочное завершение
        excludeEarlyTermination(rnode, rib);
        //-------------------------------------------------------------------
        cast_function += castRows(rnode);
        cast_function += castColumns(rnode);
        rnode->cost += cast_function;
        cast_function = 0;
        //Определяем по какой ветви идти(обходим листья в множестве)
        set<Node*>::iterator current_node = lists.begin();
        for (set<Node*>::iterator i = lists.begin(); i != lists.end(); ++i)
        {
            if ((*current_node)->cost > (*i)->cost)
                current_node = i;
        }
        chead = *current_node;
        if (steps == 1) lnode->cost = 0;
    }

    auto wayPushBack = [](Node*& node, unsigned short int index) -> pair<unsigned short, unsigned short>
    {
        pair<unsigned short, unsigned short> end_way = (node->matrix)[index][0].second != myinf.i ?
            make_pair((node->matrix)[index][0].first.first, (node->matrix)[index][0].first.second) :
            make_pair((node->matrix)[index][1].first.first, (node->matrix)[index][1].first.second);
        return end_way;
    };
    (chead->way).push_back(wayPushBack(chead, 0));
    (chead->way).push_back(wayPushBack(chead, 1));
    cout << endl << "Finish:" << endl;
    print(chead, "Result:", browser);
}

void excludeEarlyTermination(Node*& lnode, pair<unsigned short, unsigned short> rib)
{
    pair<unsigned short, unsigned short> max, min, current;
    vector<pair<short unsigned, short unsigned>> current_way;
    bool is_continue = true;
    current = max = min = rib;
    current_way.push_back(current);

    //ищем конец
    while (is_continue)
    {
        is_continue = false;
        for (auto i : lnode->way)
        {
            if (current.second == i.first)
            {
                is_continue = true;
                current = i;
                current_way.push_back(current);
                break;
            }
        }
    }
    max = current;

    is_continue = true;
    while (is_continue)
    {
        is_continue = false;
        for (auto i : lnode->way)
        {
            if (current.first == i.second)
            {
                is_continue = true;
                current = i;
                current_way.push_back(current);
                break;
            }
        }
    }
    min = current;

    max = findCurrentMatrixIndex(lnode, make_pair(max.second, min.first));
    (lnode->matrix)[max.first][max.second].second = myinf.i;
}

pair<unsigned short, unsigned short> findCurrentMatrixIndex(Node*& lnode, pair<unsigned short, unsigned short> rib)
{
    pair<unsigned short, unsigned short> ind;

    for (unsigned short i = 0; i < lnode->size; ++i)
    {
        if ((lnode->matrix)[i][0].first.first == rib.first)
        {
            ind.first = i;
            break;
        }
    }

    for (unsigned short i = 0; i < lnode->size; ++i)
    {
        if ((lnode->matrix)[0][i].first.second == rib.second)
        {
            ind.second = i;
            break;
        }
    }
    return ind;
}
