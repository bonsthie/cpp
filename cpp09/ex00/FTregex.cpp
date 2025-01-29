#include <FTregex.h>

FTregex::FTregex(const std::string &pattern) {
    int status = regcomp(&_regex, pattern.c_str(), REG_EXTENDED);
    if (status)
        throw regex_err(status, _regex);
}

FTregex::FTregex(const char *pattern) {
    int status = regcomp(&_regex, pattern, REG_EXTENDED);
    if (status)
        throw regex_err(status, _regex);
}

FTregex::~FTregex() { regfree(&_regex); }

FTregMatch FTregex::match(const std::string &input) const {
    size_t                  nGroups = _regex.re_nsub + 1;
    std::vector<regmatch_t> pmatch(nGroups);
    FTregMatch              groups;

    int status = regexec(&_regex, input.c_str(), nGroups, pmatch.data(), 0);
    if (status != 0)
        throw regex_err(status, _regex);
    for (size_t i = 0; i < nGroups; ++i) {
        if (pmatch[i].rm_so != -1) {
            groups.push_back(input.substr(pmatch[i].rm_so,
                                          pmatch[i].rm_eo - pmatch[i].rm_so));
        } else {
            groups.push_back("");
        }
    }
    return groups;
}

int FTregex::captureGroupSize(void) const { return _regex.re_nsub; }

FTregex::regex_err::regex_err(int status, const regex_t &regex) {
    char errorBuffer[256];
    regerror(status, &regex, errorBuffer, sizeof(errorBuffer));
    _msg = "FTregex compilation error: " + std::string(errorBuffer);
}

FTregex::regex_err::~regex_err() throw() {}

const char *FTregex::regex_err::what() const throw() { return _msg.c_str(); }
