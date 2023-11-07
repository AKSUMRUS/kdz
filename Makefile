CCOMPILER = g++
BUILD_FOLDER = build

.PHONY: all
all: compile basic big strings

.PHONY: basic
basic: compile generate_tests insertion_sort merge_sort

.PHONY: big
big: compile generate_big_tests merge_sort heap_sort skip_list_sort quick_sort quick_5_sort

.PHONY: strings
strings: compile generate_string_tests insertion_string_sort insertion_string_binsearch_sort

.PHONY: compile
compile:
	mkdir -p $(BUILD_FOLDER)

.PHONY: merge_sort
merge_sort: compile merge_sort.cpp
	$(CCOMPILER) merge_sort.cpp -o merge_sort
	mv merge_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/merge_sort

.PHONY: quick_sort
quick_sort: compile quick_sort.cpp
	$(CCOMPILER) quick_sort.cpp -o quick_sort
	mv quick_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/quick_sort

.PHONY: quick_5_sort
quick_5_sort: compile quick_5_sort.cpp
	$(CCOMPILER) quick_5_sort.cpp -o quick_5_sort
	mv quick_5_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/quick_5_sort

.PHONY: insertion_sort
insertion_sort: compile insertion_sort.cpp
	$(CCOMPILER) insertion_sort.cpp -o insertion_sort
	mv insertion_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/insertion_sort

.PHONY: insertion_string_sort
insertion_string_sort: compile insertion_string_sort.cpp
	$(CCOMPILER) insertion_string_sort.cpp -o insertion_string_sort
	mv insertion_string_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/insertion_string_sort

.PHONY: insertion_string_binsearch_sort
insertion_string_binsearch_sort: compile insertion_string_binsearch_sort.cpp
	$(CCOMPILER) insertion_string_binsearch_sort.cpp -o insertion_string_binsearch_sort
	mv insertion_string_binsearch_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/insertion_string_binsearch_sort

.PHONY: heap_sort
heap_sort: compile heap_sort.cpp
	$(CCOMPILER) heap_sort.cpp -o heap_sort
	mv heap_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/heap_sort

.PHONY: skip_list_sort
skip_list_sort: compile skip_list_sort.cpp
	$(CCOMPILER) skip_list_sort.cpp -o skip_list_sort
	mv skip_list_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/skip_list_sort

.PHONY: generate_tests
generate_tests: 
	python3 generate_tests.py

.PHONY: generate_big_tests
generate_big_tests:
	python3 generate_big_tests.py

.PHONY: generate_string_tests
generate_string_tests:
	python3 generate_string_tests.py
	
.PHONY: clean
clean:
	rm -r $(BUILD_FOLDER)
