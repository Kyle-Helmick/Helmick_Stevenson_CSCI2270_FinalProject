#include "Graph.h"
using namespace std;

Graph::Graph()
{
    //ctor
}

void Graph::addEdge()
{
    srand(time(NULL));
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        for(int j = 0; j < vertices.size(); j++)
        {
            int randomval = rand()%4;
            if(randomval == 1)
            {
                if(i != j)
                {
                    for(int k = 0; k < vertices[i].adj.size(); k++)
                    {
                        if(vertices[j].name == vertices[i].adj[k].v->name)
                        {
                            found = true;
                        }
                    }
                    if(found == false)
                    {
                        vertex_adj av;
                        vertex_adj ov;
                        av.v = &vertices[j];
                        ov.v = &vertices[i];
                        //cout << "flag" << endl;
                        vertices[i].adj.push_back(av);
                        vertices[j].adj.push_back(ov);
                    }
                    found = false;
                }
            }
        }

    }
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].adj.empty() == true)
        {
            vertex_adj av;
            vertex_adj ov;
            av.v = &vertices[0];
            ov.v = &vertices[i];
            vertices[i].adj.push_back(av);
            vertices[0].adj.push_back(ov);
        }
        //cout << "flag 2" << endl;
    }
}

void Graph::addVertex(string city_name)
{
    vertex_city v;
    v.name = city_name;
    vertices.push_back(v);
}

void Graph::print()
{
    vertices[0].p_controlled = true;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].p_controlled == true)
        {
            cout << vertices[i].name << endl;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "\t" << vertices[i].adj[j].v->name << endl;
            }
        }
        if(vertices[i].p_controlled == false)
        {
            cout << vertices[i].name << endl;
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout << "\t" << vertices[i].adj[j].v->name << endl;
            }
        }
    }
}

Graph::~Graph()
{
    //dtor
}
