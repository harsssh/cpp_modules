#ifndef CPP_MODULES_OPTION_H
#define CPP_MODULES_OPTION_H

template<typename T>
class Option {
public:
	Option() {}

	Option(const Option &other) { (void) other; }

	virtual ~Option() {}

	Option &operator=(const Option &other) {
		(void) other;
		return *this;
	}

	virtual T unwrap() const = 0;

	virtual bool isSome() const = 0;
};

#endif //CPP_MODULES_OPTION_H
