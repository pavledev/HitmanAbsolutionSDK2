#pragma once

template<class T>
class TBinaryTreeNode
{
public:
    int m_nBalance;
    TBinaryTreeNode<T>* m_pParent;
    TBinaryTreeNode<T>* m_pLeft;
    TBinaryTreeNode<T>* m_pRight;
    T m_data;

    static TBinaryTreeNode<T>* GetNextNode(TBinaryTreeNode<T>* pNode)
    {
        TBinaryTreeNode<T>* v1;
        TBinaryTreeNode<T>* result;
        TBinaryTreeNode<T>* i;

        v1 = pNode;
        result = pNode->m_pRight;

        if (result)
        {
            for (i = result->m_pLeft; i; i = i->m_pLeft)
            {
                result = i;
            }
        }
        else
        {
            result = pNode->m_pParent;

            if (result)
            {
                if (result->m_pLeft == pNode)
                {
                    return result;
                }

                do
                {
                    if (result->m_pLeft == v1)
                    {
                        break;
                    }

                    v1 = result;
                    result = result->m_pParent;
                } while (result);
            }

            result = v1->m_pParent;

            if (!result)
            {
                result = v1;
            }
        }

        return result;
    }

    T Data()
    {
        return this->m_data;
    }
};
