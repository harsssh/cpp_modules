#ifndef CPP_MODULES_BRAIN_H
#define CPP_MODULES_BRAIN_H

#include <string>

class Brain {
private:
	static const size_t maxIdeas = 100;
	std::string ideas_[Brain::maxIdeas];

public:
	Brain();

	Brain(const Brain &other);

	~Brain();

	Brain &operator=(const Brain &other);

	void setIdea(size_t index, const std::string &idea);

	const std::string &getIdea(size_t index) const;
};

#endif //CPP_MODULES_BRAIN_H
