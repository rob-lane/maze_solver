#include "data_structure.h"

data_structure::data_structure(char& structure_type) { 
  if (structure_type == 's') { 
    m_s = new std::stack<Point>;
    m_q = NULL;
  } else if (structure_type == 'q') { 
    m_q = new std::queue<Point>;
    m_q = NULL;
  }
}

data_structure::~data_structure() { 
  if (m_s) { 
    delete m_s;
    m_s = NULL;
  }
  if (m_q) { 
    delete m_q;
    m_q = NULL;
  }
}

void data_structure::push(Point p) { 
  if (m_s) { 
    m_s->push(p);
  } else if (m_q) { 
    m_q->push(p);
  }
}

void data_structure::pop() { 
  if (m_s) { 
    m_s->pop();
  } else if (m_q) { 
    m_q->pop();
  }
}

Point data_structure::next() { 
  if (m_s) { 
    return m_s->top();
  } else if (m_q) { 
    return m_q->front();
  }
  return Point(-1, -1);
}

bool data_structure::empty() { 
  if (m_s) { 
    return m_s->empty();
  } else if (m_q) { 
    return m_q->empty();
  }
  return true;
}
