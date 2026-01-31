# Customer Billing System - C Programming

A comprehensive command-line billing system built in C for managing customers, products, inventory, and generating invoices.

## Features

### Customer Management
- Add new customers with contact details
- View all customers
- Search customers by ID

### Product Management
- Add new products with pricing
- View all products
- Update stock quantities (add/remove)
- Search products by ID

### Billing System
- Create invoices with multiple items
- Automatic stock deduction
- Tax calculation (10%)
- Professional invoice generation
- Bill history tracking

## Compilation

### Linux/Mac:
```bash
gcc billing_system.c -o billing_system
./billing_system
```

### Windows (MinGW):
```bash
gcc billing_system.c -o billing_system.exe
billing_system.exe
```

### Windows (Visual Studio):
```bash
cl billing_system.c
billing_system.exe
```

## Usage Guide

### Initial Setup
The system comes with sample data:
- 3 pre-loaded customers (IDs: 1, 2, 3)
- 5 pre-loaded products (IDs: 101-105)

### Creating a Bill
1. Go to Main Menu → Billing → Create New Bill
2. Enter Customer ID (e.g., 1 for John Doe)
3. Enter Product ID (e.g., 101 for Laptop)
4. Enter quantity
5. Choose to add more items or complete the bill
6. Invoice will be generated and saved

### Adding New Customers
1. Main Menu → Customer Management → Add New Customer
2. Enter customer details (name, phone, email)
3. Customer ID is auto-generated

### Managing Products
1. Main Menu → Product Management
2. Add products, view inventory, or update stock levels

### Viewing Bills
All bills are saved to `bills.txt` and can be viewed through the Billing menu.

## Sample Data

### Customers:
- ID 1: John Doe (555-0101)
- ID 2: Jane Smith (555-0102)
- ID 3: Bob Johnson (555-0103)

### Products:
- ID 101: Laptop ($899.99, Stock: 15)
- ID 102: Mouse ($25.50, Stock: 50)
- ID 103: Keyboard ($75.00, Stock: 30)
- ID 104: Monitor ($299.99, Stock: 20)
- ID 105: USB Cable ($12.99, Stock: 100)

## File Structure

```
billing_system.c    - Main program
bills.txt          - Bill history (generated when bills are created)
```

## Technical Details

- **Language**: C
- **Max Customers**: 100
- **Max Products**: 50
- **Max Items per Bill**: 20
- **Tax Rate**: 10%

## System Requirements

- C compiler (GCC, MinGW, MSVC, or Clang)
- Standard C libraries (stdio.h, stdlib.h, string.h, time.h)
- Console/Terminal

## Features in Detail

### Invoice Format
- Professional layout with borders
- Bill ID and date
- Customer information
- Itemized list with quantities and prices
- Subtotal, tax, and total calculations

### Stock Management
- Automatic inventory updates when bills are created
- Stock validation before purchase
- Manual stock adjustment options

### Data Persistence
- Bill history saved to text file
- In-memory storage for customers and products
- (Can be extended to file-based storage)

## Future Enhancements

Possible additions:
- File-based storage for customers and products
- Edit/delete functionality
- Customer purchase history
- Sales reports and analytics
- Discount management
- Multiple tax rates
- Payment tracking

## License

Free to use and modify for educational and commercial purposes.