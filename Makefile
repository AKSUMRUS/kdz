CCOMPILER = g++
BUILD_FOLDER = build

.PHONY: all
all: compile generate_tests merge_sort insertion_sort heap_sort skip_list_sort insertion_binsearch_sort

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

.PHONY: insertion_sort
insertion_sort: compile insertion_sort.cpp
	$(CCOMPILER) insertion_sort.cpp -o insertion_sort
	mv insertion_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/insertion_sort

.PHONY: insertion_binsearch_sort
insertion_binsearch_sort: compile insertion_binsearch_sort.cpp
	$(CCOMPILER) insertion_binsearch_sort.cpp -o insertion_binsearch_sort
	mv insertion_binsearch_sort $(BUILD_FOLDER)
	./$(BUILD_FOLDER)/insertion_binsearch_sort

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
	
.PHONY: clean
clean:
	rm -r $(BUILD_FOLDER)
