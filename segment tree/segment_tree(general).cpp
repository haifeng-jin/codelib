struct SegmentTree
{

    struct Node
    {
        int l, r;
        Node *pleft, *pright;
        //add the needed variable
    }tree[MAX_INTERVAL *4];

    int node_cnt;

    void init()
    {
        node_cnt = 0;
    }

    Node* new_node()
    {
        node_cnt++;
        return tree + node_cnt;
    }

    void build_tree(Node *proot, int s, int e)
    {
        proot->l = s;
        proot->r = e;
        //init the variables
        if (s == e)
        {
            proot->pleft = proot->pright = NULL;
            return;
        }
        int mid = (s + e) / 2;
        build_tree(proot->pleft = new_node(), s, mid);
        build_tree(proot->pright = new_node(), mid + 1, e);
    }

    void pull_up(Node *proot)
    {
            //do something
    }

    void push_down(Node *proot)
    {
            //do something
    }

    void update(Node *proot, int start, int end, int value)
    {
        if (start > proot->r || end < proot->l)
            return;
        start = max(start, proot->l);
        end = min(end, proot->r);
        if (start == proot->l && end == proot->r)
        {
            //do something
            return;
        }
        push_down(proot);
        update(proot->pleft, start, end, value);
        update(proot->pright, start, end, value);
        pull_up(proot);
    }

    int query(Node *proot, int start, int end)
    {
        int ret = proot->value;
        if (start > proot->r || end < proot->l)
            return 0;
        start = max(start, proot->l);
        end = min(end, proot->r);
        if (start == proot->l && end == proot->r)
        {
            //do something
        }
        push_down(proot);
        ret = max(ret, query(proot->pleft, start, end));
        ret = max(ret, query(proot->pright, start, end));
        pull_up(proot);
        return ret;
    }
};
