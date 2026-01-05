# Student Grade Management System 📚

A console-based application built to manage student records, grades, and academic performance. This project marks a specific milestone in my transition from procedural **C** programming to Object-Oriented **Modern C++**.

## 🚀 About The Project

I built this project immediately after learning the **C++ Standard Template Library (STL)**, specifically `std::vector`. The goal was to move away from theoretical tutorials and apply the concepts in a practical scenario instantly.

This codebase represents:
* **The shift from C to C++:** Moving from fixed-size arrays to dynamic vectors.
* **Object-Oriented Design:** Encapsulating data in `Student` and `GradeBook` classes.
* **Manual Iterator Management:** Using explicit iterators to understand how C++ handles memory and traversal "under the hood" before moving to modern abstractions.

## ⚠️ Current Limitations (Work in Progress)

* **Top Performers Logic:** The `displayTopPerformers` function currently displays the **first N students** added to the system rather than the actual highest scorers.
    * *Reason:* I have not yet implemented `<algorithm>` or `std::sort`. As I move into Data Structures and Algorithms (DSA), I will update this to sort the vector by GPA before displaying.

## 🛠 Features

* **Student Management:** Add new students and remove existing ones by Roll Number.
* **Grade Tracking:** Add subjects and marks dynamically to any student.
* **Performance Analysis:**
    * Calculate individual averages and assign Letter Grades (A-F).
    * Calculate the overall Class Average.
* **Reporting:** Generate individual student reports or view the entire class list.
* **Top 3 Performers:** *Currently a placeholder (see Limitations above).*

## 💻 Technical Concepts Implemented

* **Classes & Objects:** Encapsulation of student data.
* **STL Vectors:** Dynamic storage for `Student` objects, subjects, and grades.
* **Iterators:** Explicit use of `vector<type>::iterator` for traversing data structures.
* **Pointers:** Referencing objects within vectors for updates.
* **Switch-Case Logic:** Menu-driven CLI interface.

## ⚙️ How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/riturajdroid/student-grade-system.git](https://github.com/riturajdroid/student-grade-system.git)
    ```
2.  **Navigate to the directory:**
    ```bash
    cd student-grade-system
    ```
3.  **Compile the code:**
    ```bash
    g++ main.cpp -o gradebook
    ```
4.  **Run the application:**
    ```bash
    ./gradebook
    ```

## 🔮 Future Improvements (Roadmap)

As I continue to learn Data Structures and Algorithms (DSA), I plan to update this project with:

* **Sorting Algorithms:** Implementing `std::sort` to fix the "Top Performers" feature.
* **Modern Loops:** Refactoring explicit iterators to C++11 range-based `for` loops for cleaner code.
* **Input Validation:** Preventing duplicate roll numbers and handling non-integer inputs.
* **File Handling:** Saving student data to a `.txt` or `.csv` file so data persists after the program closes.

## 🤝 Contributing

This is a learning project, but suggestions are welcome! If you see a way to optimize the vector operations or improve the class design, feel free to open an issue.

---

*Built with C++ and a Growth Mindset.*
