
#include<iostream>

using namespace std;

const int MAX_N = 50010;

int set[MAX_N];

int r[MAX_N];

void init(int n)

{

    for (int i = 0; i <= n; i++)

    {

        set[i] = i;

        r[i] = 0;

    }

}

//原理如下：

//首先，集合里的每个点我们都记录它与它这个集合(或者称为子树)的根结点的相对关系relation。0表示它与根结点为同类，1表示它吃根结点，2表示它被根结点吃。

//那么判断两个点a, b的关系，我们令p = Find(a), q = Find(b)，即p, q分别为a, b子树的根结点。

//1. 如果p != q，说明a, b暂时没有关系，那么关于他们的判断都是正确的，然后合并这两个子树。这里是关键，如何合并两个子树使得合并后的新树能保证正确呢？

//这里我们规定只能p合并到q(刚才说过了，启发式合并的优化效果并不那么明显，如果我们用启发式合并，就要推出两个式子，而这个推式子是件比较累的活...所以

//一般我们都规定一个子树合到另一个子树)。那么合并后，p的relation肯定要改变，那么改成多少呢？这里的方法就是找规律，列出部分可能的情况，就差不多能推出

//式子了。这里式子为 : tree[p].relation = (tree[b].relation - tree[a].relation + 2 + d) % 3; 这里的d为判断语句中a, b的关系。还有个问题，我们是否需要

//遍历整个a子树并更新每个结点的状态呢？答案是不需要的，因为我们可以在Find()函数稍微修改，即结点x继承它的父亲(注意是前父亲，因为路径压缩后父亲就会改变)，

//即它会继承到p结点的改变，所以我们不需要每个都遍历过去更新。

//2. 如果p = q，说明a, b之前已经有关系了。那么我们就判断语句是否是对的，同样找规律推出式子。即if((tree[b].relation + d + 2) % 3 != tree[a].relation), 

//那么这句话就是错误的。

//3. 再对Find()函数进行些修改，即在路径压缩前纪录前父亲是谁，然后路径压缩后，更新该点的状态(通过继承前父亲的状态，这时候前父亲的状态是已经更新的)。

int cha(int x)

{

    if (x == set[x])

        return x;

    int tx = cha(set[x]);

    //关键,此处要理解，若上一次合并两个高度为2的树，合并后一棵树高度变为3，则在下一次查询时完成所有结点状态的更新。

    //查找中的更新 压缩路径中的更新

    r[x] = (r[x] + r[set[x]]) % 3;

    //return tx; 错误，要完成路径的更新

    return set[x] = tx;

}

void unite(int x, int y, int type)

{

    int tx = cha(x);

    int ty = cha(y);

    set[ty] = tx;//合并这两棵树

    r[ty] = (r[x] + type - 1 - r[y] + 3) % 3;//关键，修改相对关系

    return;

}

int main()

{

#ifdef ONLINE_JUDGE

#else

    freopen("D:\\in.txt", "r", stdin);

    freopen("D:\\out.txt", "w", stdout);

#endif

    int n(0), m(0);

    scanf("%d%d", &n, &m);

    init(n);

    int type(0), x(0), y(0);

    int ans(0);

    for (int i = 1; i <= m; i++)

    {

        scanf("%d%d%d", &type, &x, &y);

        if (x > n || y > n || (type == 2 && x == y))

        {

            ans++;

            continue;

        }

        if (cha(x) == cha(y))//在同一棵树中

        {

            if ((r[y] - r[x] + 3) % 3 != (type - 1))

            {

                ans++;

            }

        }

        else

        {

            (unite(x, y, type));//不在一棵树中，则合并

        }

    }

    printf("%d\n", ans);

}
