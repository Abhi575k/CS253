# CS253
 
## Requirements

* C++ compiler with at least C++11 support.
* boost library & development headers (1.64 or later).
* [crowcpp](https://crowcpp.org/getting_started/setup/linux/).

## How to run the code
First of all you have to clone this repository or fork it and then clone your forked repository (recommended). In case of this repositry you can clone it by typing the following command in your terminal:

```bash
git clone https://your-username/CS253.git
```
then change the directory to the cloned one

```bash
cd CS253
```
you can run **ls** to verfiy the catalogue structure is like above.
Then go into the `src` directory and compile `main.cpp` using following command:

```bash
cd src
g++ main.cpp -lpthread
```
you can run project using :
```
./a.out
```
to explore some feature of crow go to  `examples` directory and run any `example_x.cpp` file you want:

```bash
cd ../examples
g++ example_x.cpp -lpthread
./a.out
```
There should be printed log information on your command line then you can open web browser and go to the (http://0.0.0.0:Y)  `Ex: Y=18018`
If everythings works fine the browser should render `landing page` and the rest of the page.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
